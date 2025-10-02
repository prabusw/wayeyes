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

- Place the executable script swayeyes in $HOME/.local/bin/swayeyes
  and ensure that it's in your $PATH
- If the script location changes, update service and i3blocks scripts
- In sway config file add a keybind to "swayeyes toggle"
- Use the available i3blocks script, if required

Here are the steps to use with OpenRC user service as tested in Alpine
Linux v3.22:
- Place the service file in $HOME/.config/rc/init.d/swayeyes
- Add and start swayeyes service using the below commands:
  ```
  rc-update -U add swayeyes
  rc-service -U start swayeyes
  ```

The systemd script has not been tested. Here are the steps to use with
systemd:
- Place the service file in $HOME/.config/systemd/user/swayeyes.service
- Add and start the service using the below commands:
  ```
  systemctl --user daemon-reload
  systemctl --user enable swayeyes.service
  systemctl --user start swayeyes.service
  ```

Refer to my [dotiles](https://git.sr.ht/~prabuanand/dotfiles) for how
this tool is used in Alpine Linux, where it integrated with OpenRC and
[i3blocks](https://github.com/vivien/i3blocks), a status provider for
swaybar.


Copyright (C) 2025-2025 Prabu Anand Kalivaradhan

swayeyes comes with NO WARRANTY, to the extent permitted by
law. Please feedback, if there are issues when using the tool.

Home page:git.sr.ht/~prabuanand/swayeyes
