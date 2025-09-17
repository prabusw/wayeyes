#  swayeyes - Lightweight tool for Sway to prevent eye strain

Swayeyes is a lightweight tool preventing eye strain for
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
- Amend sway config file to add "swayeyes toggle" shortcut.
- Use the available i3blocks script, if required.

Here are the steps to use with OpenRC user service as tested in Alpine
Linux v3.22:
- OpenRC user service requires the service file to be in
  ~/.config/rc/init.d/swayeyes
- rc-update -U add swayeyes

I have not tested the systemd script. Here are the steps to use with
systemd:
- Place the service file in ~/.config/systemd/user/swayeyes.service
- systemctl --user daemon-reload
- systemctl --user enable swayeyes.service
- systemctl --user start swayeyes.service

Refer to my [dotiles](https://git.sr.ht/~prabuanand/dotfiles) for how
this tool is used in Alpine Linux, where it integrated with OpenRC and
[i3blocks](https://github.com/vivien/i3blocks), a status provider for
swaybar.

Please feedback, if there are issues when using the tool.
