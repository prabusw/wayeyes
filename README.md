#  Wayeyes - Lightweight RSI tool for wlroots based Wayland compositors

Wayeyes is a lightweight RSI tool for wlroots based Wayland
compositors like [Sway](https://swaywm.org/). This utility is designed
to work in a standalone mode by starting from compositor configuration
file or with a service manager like OpenRC or systemd and requires
[wlopm](https://git.sr.ht/~leon_plickat/wlopm) and libnotify.

The tool has the following features:

* Schedules regular screen blanking to prevent eye strain.
* Pre-blanking notification alerts.
* When the system resumes from suspend, resets break timer via
  SIGUSR2.
* SIGUSR1 can be used to pause and unpause the tool.
* The tool by default blanks all outputs. If an output name is passed
  an argument, only that output will be blanked.
* When used with tools like
[i3blocks](https://github.com/vivien/i3blocks) visual indicators can
be added to bar.

Here are the steps to get the tool working:

- Place the executable in your $PATH.
- To start wayeyes, either add an entry in your compositor
  configuration file or use a User service manager
- Add a keybind to "pkill -SIGUSR1 wayeyes" in your compositor
   configuration file to pause and unpause.
- Use the available i3blocks scripts, if visual indicators on bar is
  required.
- Use the after-resume hook with SIGUSR2 to reset the break timer. For
  swayidle, use "after-resume 'pkill -SIGUSR2 wayeyes'". For manual
  suspend scripts: add 'pkill -SIGUSR2 wayeyes' after the suspend
  command returns.

## Build & Install

```sh
cc -O2 -o wayeyes wayeyes.c
install -m755 wayeyes $HOME/.local/bin/
```

## Using with i3blocks

Here are the steps to use with i3blocks as tested

- Place the given i3blocks script in your script folder.
- Signal 3 is defined in the utility to communicate with i3blocks to
  update the icons. If this needs to be changed, change the signal
  number both in the utility and i3blocks configuration file.
- Add a wayeyes section to i3blocks config file
  $HOME/.config/i3blocks/config as shown below:

```ini
[wayeyes]
interval=60
signal=3
min_width=20
```

## Using with openRC

Here are the steps to use with OpenRC user service as tested in Alpine
Linux v3.24.

- Edit the location of executable, if different from
  $HOME/.local/bin/wayeyes.
- Place the service file in $HOME/.config/rc/init.d/wayeyes
- Add and start wayeyes service using the below commands:
  ```
  rc-update -U add wayeyes
  rc-service -U start wayeyes
  ```

## Using with systemd

The systemd script has not been tested. Here are the steps to use with
systemd:
- Place the service file in $HOME/.config/systemd/user/wayeyes.service
- Add and start the service using the below commands:
  ```
  systemctl --user daemon-reload
  systemctl --user enable wayeyes.service
  systemctl --user start wayeyes.service
  ```

## Testing

The utility can also be run directly in a terminal for testing
purposes. To test the script directly without a service manager:

```
wayeyes
```

The state file is at $XDG_RUNTIME_DIR/wayeyes.state.

Refer to my [dotfiles](https://git.sr.ht/~prabuanand/dotfiles) to view
how this tool is used in Alpine Linux, where it is integrated with
Sway and i3blocks.

## LLM usage

The utility and associated service files have been created using LLM
like claude.

Copyright (C) 2025-2026 Prabu Anand Kalivaradhan

wayeyes comes with NO WARRANTY, to the extent permitted by law. Please
report any issues when using the tool.

Home page: https://git.sr.ht/~prabuanand/wayeyes
