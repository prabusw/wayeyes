#  swayeyes - Lightweight tool for Sway to prevent eye strain

Swayeyes is a lightweight tool to reduce eye strain for
[Sway](https://swaywm.org/). This shell script can be used either as a
standalone tool or used with a service manager like OpenRC or systemd.

The tool currently has the following features:

* Schedules regular screen blanking to prevent eye strain.
* Pre-blanking notification alerts.
* Handles time jumps caused by suspend/resume.
* Detailed logging.
* Toggle option available to pause and resume the script.

Here are the steps to get the tool working:

- Place the executable script swayeyes in your path.
- Verify and update the path for scripts, if required.
- In sway config file add a keybind to "swayeyes toggle".
- Use the available i3blocks script, if required.

Here are the steps to use with OpenRC user service as tested in Alpine
Linux v3.22:
- To use with OpenRC user service, place the service file in
  ~/.config/rc/init.d/swayeyes
- Verify and update the path for scripts, if required.
- Add swayeyes service using the command "rc-update -U add swayeyes"

The systemd script has not been tested. Here are the steps to use with
systemd:
- Place the service file in ~/.config/systemd/user/swayeyes.service
- Issue the following commands in sequence
  systemctl --user daemon-reload
  systemctl --user enable swayeyes.service
  systemctl --user start swayeyes.service

Refer to my [dotiles](https://git.sr.ht/~prabuanand/dotfiles) for how
this tool is used in Alpine Linux, where it integrated with OpenRC and
[i3blocks](https://github.com/vivien/i3blocks), a status provider for
swaybar.


Copyright (C) 2025-2025 Prabu Anand Kalivaradhan

swayeyes comes with NO WARRANTY, to the extent permitted by
law. Please feedback, if there are issues when using the tool.

Home page:git.sr.ht/~prabuanand/swayeyes
