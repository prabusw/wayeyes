#  Wayeyes - Lightweight tool to reduce eye strain for Wayland compositors

Wayeyes is a lightweight tool to reduce eye strain for Wayland
compositors like [Sway](https://swaywm.org/), Weston etc. This shell
script is designed to work with a service manager like OpenRC or
systemd and requires [wlopm](https://git.sr.ht/~leon_plickat/wlopm) utility.

The tool currently has the following features:

* Schedules regular screen blanking to prevent eye strain.
* Pre-blanking notification alerts.
* Handles time jumps caused by suspend/resume.
* Detailed logging.
* Toggle option available via a separate toggle script to pause and
  resume the service, which depends on either openRC or systemd .
* Supports [i3blocks](https://github.com/vivien/i3blocks), a status
provider for swaybar.

Here are the steps to get the tool working:

- Place the executable script wayeyes in $HOME/.local/bin/wayeyes
  and ensure that it's in your $PATH
- If the script location changes, update service and i3blocks scripts
- Place toggle_wayeyes in $HOME/.local/bin/ and add a keybind to it
  in sway configuration file.
- Use the available i3blocks and toggle_wayeyes scripts, if required.

## Using with openRC

Here are the steps to use with OpenRC user service as tested in Alpine
Linux v3.24:
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
The script can also be run directly in a terminal for testing
purposes. To test the script directly without a service manager:

```
wayeyes
```

Use Ctrl+C to stop. All output goes to the log file at
$XDG_DATA_HOME/wayeyes/wayeyes.log

Refer to my [dotfiles](https://git.sr.ht/~prabuanand/dotfiles) to view
how this tool is used in Alpine Linux, where it is integrated with
OpenRC and i3blocks.


Copyright (C) 2025-2026 Prabu Anand Kalivaradhan

wayeyes comes with NO WARRANTY, to the extent permitted by
law. Please feedback, if there are issues when using the tool.

Home page: https://git.sr.ht/~prabuanand/wayeyes
