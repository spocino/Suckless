# dwm - dynamic window manager

Personal fork of dwm with changes, and patches to suit my needs.


Dwm is an extremely fast, small, and dynamic window manager for X.


## Requirements

In order to build dwm you need the Xlib header files.

You also want `st` and my fork of [dmenu](https://bitbucket.org/natemaia/dmenu)
for the default keybindings to work, or edit `config.def.h`.

The default font in config.h is [SauceCodePro Nerd Font](https://github.com/ryanoasis/nerd-fonts/tree/master/patched-fonts/SourceCodePro)

## Patches

- [attachaside](https://dwm.suckless.org/patches/attachaside/)
- [focusonnetactive](https://dwm.suckless.org/patches/focusonnetactive/) *modified*
- [gaplessgrid](https://dwm.suckless.org/patches/gaplessgrid/) *modified*
- [movestack](https://dwm.suckless.org/patches/movestack/)
- [noborder](https://dwm.suckless.org/patches/noborder/) *modified*
- [pertag](https://dwm.suckless.org/patches/pertag/) *modified*
- [stackmfact](https://dwm.suckless.org/patches/stackmfact/) *modified*
- [sticky](https://dwm.suckless.org/patches/sticky/)
- [tagintostack](https://dwm.suckless.org/patches/tagintostack/)
- [tilegap](https://dwm.suckless.org/patches/tilegap/)
- [viewontag](https://dwm.suckless.org/patches/viewontag/) *modified*
- [warp](https://dwm.suckless.org/patches/warp/) *modified*
- [zoomswap](https://dwm.suckless.org/patches/zoomswap/)

- Gaps can be changed on the fly and are stored separately for each tag, see man dwm(1).
- Mouse warp on keybindings for client movement and focus change *only*.
- Floating and fullscreen clients have borders disabled see `floatborder` in `config.def.h`.
- Current window title in the statusbar is off by default see `bartitle` in `config.def.h`.


## Installation

Edit `config.mk` to match your local setup (installed to `/usr` namespace by default).
Remove the default `config.h`, a new one will be created from `config.def.h` at build time.

Enter the following command to build and install dwm (as root if needed).
```
make clean install
```

## Running dwm

Add the following to `~/.xinitrc`
```
exec dwm
```
Alternatively to restart dwm without logging out or closing applications, load dwm in a *while* loop
```
while true; do
    dwm >/dev/null 2>&1
done
```
dwm can then be restarted without destroying other X windows with the usual Mod-Shift-q key combo


To display additional status info in the bar, the following can be used in `~/.xinitrc`
```
while xsetroot -name "`date` `uptime -p`"; do
    sleep 1
done &

exec dwm
```


In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.
```
DISPLAY=foo.bar:1 exec dwm
```
This will start dwm on display :1 of the host foo.bar.


## Configuration

Configuration of dwm is done by creating a custom `config.h` and (re)compiling.
