#  swayeyes - Lightweight tool for Sway to prevent eye strain

swayeyes is a lightweight shell script for [Sway](https://swaywm.org/) aimed
at preventing eye strain.

The tool currently has the following features:

* Schedules regular screen blanking to prevent eye strain.
* Pre-blanking notification alerts.
* Handles time jumps caused by suspend/resume.
* Detailed logging.
* Can run as as a user service with OpenRC, which can be easily
  adapted to systemd.
* Screen blanking can be paused or resumed.
* Provides an icon in the bar, when used with i3blocks.

The script is intended to be used with a service manager like
openRC. A systemd user service can be created based on the OpenRC
script.

After downloading the repo, follow these steps to get the tool working
in OpenRC user service setup:

#. Place the scripts swayeyes and toggle_swayeyes in your path.
#. Verify and update the path for scripts, if required.
#. Amend sway config file for toggle_swayeyes shortcut.
#. If using OpenRC user service, use the script openrc/swayeyes.
#. If using i3blocks, use the available i3blocks script.

Refer to my [dotiles](https://git.sr.ht/~prabuanand/dotfiles) for how
this tool is used in Alpine Linux, where it integrated with OpenRC,
[i3blocks](https://github.com/vivien/i3blocks), a status provider for
swaybar.

Please feedback, if there are issues when using the tool.
