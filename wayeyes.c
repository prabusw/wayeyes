#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdint.h>
#include <sys/timerfd.h>
#include <poll.h>

#define INTERVAL     900   /* 15 minutes between breaks */
#define PRE_ALERT     60   /* 1 minute warning */
#define SHORT_BREAK   20   /* short break duration */
#define LONG_BREAK    60   /* long break every 4th */
#define I3SIGNAL       3   /* i3blocks signal number */

static volatile sig_atomic_t paused = 0;
static volatile sig_atomic_t resume = 0;
static volatile sig_atomic_t quit   = 0;

static void handle_sigusr1(int sig) { (void)sig; paused = !paused; }
static void handle_sigusr2(int sig) { (void)sig; resume = 1; }
static void handle_sigterm(int sig) { (void)sig; quit = 1; }

static char state_file[256];
static char *output_arg = NULL;

static void write_state(const char *state) {
    FILE *f = fopen(state_file, "w");
    if (f) { fputs(state, f); fclose(f); }
    char cmd[64];
    snprintf(cmd, sizeof(cmd), "pkill -RTMIN+%d i3blocks", I3SIGNAL);
    system(cmd);
}

static void blank(int off) {
    char cmd[128];
    snprintf(cmd, sizeof(cmd), "wlopm --%s '%s'",
             off ? "off" : "on",
             output_arg ? output_arg : "*");
    system(cmd);
}

static int make_timerfd(time_t seconds) {
    int fd = timerfd_create(CLOCK_MONOTONIC, TFD_CLOEXEC);
    struct itimerspec its = {
        .it_value    = { .tv_sec = seconds, .tv_nsec = 0 },
        .it_interval = { .tv_sec = 0,       .tv_nsec = 0 }
    };
    timerfd_settime(fd, 0, &its, NULL);
    return fd;
}

static void restart_timers(int *ifd, int *pfd, struct pollfd *fds, char *state) {
    close(*ifd); close(*pfd);
    *ifd = make_timerfd(INTERVAL);
    *pfd = make_timerfd(INTERVAL - PRE_ALERT);
    fds[0].fd = *pfd;
    fds[1].fd = *ifd;
    snprintf(state, 64, "running %ld", time(NULL) + INTERVAL);
    write_state(state);
}

int main(int argc, char *argv[]) {
    if (argc > 1) output_arg = argv[1];

    const char *runtime = getenv("XDG_RUNTIME_DIR");
    snprintf(state_file, sizeof(state_file), "%s/wayeyes.state",
             runtime ? runtime : "/tmp");

    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);
    signal(SIGTERM, handle_sigterm);
    signal(SIGINT,  handle_sigterm);

    int count = 0;
    int interval_fd  = make_timerfd(INTERVAL);
    int pre_alert_fd = make_timerfd(INTERVAL - PRE_ALERT);

    char state[64];
    snprintf(state, sizeof(state), "running %ld", time(NULL) + INTERVAL);
    write_state(state);

    struct pollfd fds[2] = {
        { pre_alert_fd, POLLIN, 0 },
        { interval_fd,  POLLIN, 0 }
    };

    while (!quit) {
        if (resume) {
            resume = 0;
            paused = 0;
            restart_timers(&interval_fd, &pre_alert_fd, fds, state);
            continue;
        }

        if (paused) {
            write_state("paused");
            while (paused && !quit && !resume) pause();
            if (quit) break;
            restart_timers(&interval_fd, &pre_alert_fd, fds, state);
            continue;
        }

        int ret = poll(fds, 2, -1);
        if (ret <= 0) continue;

        uint64_t exp;

        if (fds[0].revents & POLLIN) {
            read(pre_alert_fd, &exp, sizeof(exp));
            snprintf(state, sizeof(state), "pre-alert %ld", time(NULL) + PRE_ALERT);
            write_state(state);
        }

        if (fds[1].revents & POLLIN) {
            read(interval_fd, &exp, sizeof(exp));
            count++;
            int duration = (count % 4 == 0) ? LONG_BREAK : SHORT_BREAK;
            system(duration == LONG_BREAK
                ? "notify-send -a wayeyes 'Time for a long break!'"
                : "notify-send -a wayeyes 'Time for a short break!'");
            blank(1);
            write_state("blanked");
            sleep(duration);
            blank(0);
            restart_timers(&interval_fd, &pre_alert_fd, fds, state);
        }
    }

    write_state("stopped");
    close(interval_fd);
    close(pre_alert_fd);
    return 0;
}
