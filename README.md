#  swayeyes - Lightweight tool for Sway to prevent eye strain

swayeyes is a lightweight tool aimed at preventing eye strain for
[Sway](https://swaywm.org/) users. These shell scripts depend
only on tools which are built into Sway.

The tool currently has the following features:

* Schedules regular screen blanking to prevent eye strain.
* Pre-blanking notification alerts.
* Provides an icon in the bar, when used with i3blocks.
* Detailed logging.
* Can run as as a user service with OpenRC, which can be easily
  adapted to systemd.

It is recommended to use a service manager like openRC to run this
tool. A systemd user service can be created based on the OpenRC script.


Steps to get the tool working: (step 4 onwards is optional)

1. Download the repo.
2. Place the main scripts(swayeyes and toggle_swayeyes in the folder:  $HOME/.local/bin
3. Copy the OpenRC user service script(openrc/swayeyes) to the folder: $HOME/.config/rc/init.d
4. Please update the service commands in toggle_swayeyes script.
5. Create a shortcut in the sway config file: $HOME/.config/sway/config
6. If using i3blocks, copy the i3blocks script(i3blocks/swayeyes) to the folder: $HOME/.local/bin/i3blocks
7. Add an entry for swayeeys in i3blocks config file at $HOME/.config/i3blocks/config
8. Add relevent entries in your notification daemon to handle the notifications.
9. Add the necessary service management commands to manage suspend/resume events: $HOME/.local/bin/tofi-exit

Refer to my [dotiles](https://git.sr.ht/~prabuanand/dotfiles) for how
this tool is used on Alpine Linux, where it has been integrated with
OpenRC and other tools like [tofi](https://github.com/philj56/tofi), a
menu launcher, [i3blocks](https://github.com/vivien/i3blocks), a
status provider for swaybar and
[mako](https://github.com/emersion/mako), a notification server.

Please feedback, if there are issues when using the tool.
