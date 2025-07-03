#  swayeyes - Lightweight tool for Sway to prevent eye strain

swayeyes is a lightweight tool aimed at preventing eye strain for
[Sway](https://swaywm.org/). This is a simple shell script that depends
only on tools which are built into Sway.

The tool currently has the following features:

* Schedules regular screen blanking to prevent eye strain.
* Pre-blanking notification alerts.
* Provides an icon in the bar, when used with i3blocks.
* Detailed logging.
* Can run as as a user service with OpenRC, which can be easily
  adapted to systemd.
* Use toggle_swayeyes script to pause screen blanking.
* Uses swayidle to adjust the blanking time.

The script is intended to be used with a service manager like
openRC. A systemd user service can be created based on the OpenRC
script.

After downloading the repo, follow these steps to get the tool working
in OpenRC user service setup:

#. Place the scripts swayeyes and toggle_swayeyes in your path.
#. Verify and update the path for scripts, if required.
#. Amend sway config file for swayidle and toggle_swayeyes shortcut.
#. If using OpenRC user service, use the script openrc/swayeyes.
#. If using i3blocks, use the available i3blocks script.
#. Add relevent entries in your notification daemon to customize.
#. Adjust the config files to manage suspend events.

Refer to my [dotiles](https://git.sr.ht/~prabuanand/dotfiles) for how
this tool is used on Alpine Linux, where it integrated with OpenRC,
[i3blocks](https://github.com/vivien/i3blocks), a status provider for
swaybar, tofi-exit based on [tofi](https://github.com/philj56/tofi) ,
a menu launcher is used here to manage suspend events and
[mako](https://github.com/emersion/mako), a notification server.

Please feedback, if there are issues when using the tool.
