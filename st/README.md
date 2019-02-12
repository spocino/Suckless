# fork of st with patches & changes

st is a simple terminal emulator for X which sucks less.

### Changes

- New dark color scheme
- Hide mouse cursor while typing
- Scrollback with mouse support

### Requirements

In order to build st you need the Xlib header files.
The default font in config.h is [SauceCodePro Nerd Font](https://github.com/ryanoasis/nerd-fonts/tree/master/patched-fonts/SourceCodePro)


### Installation

Edit `config.mk` to match your local setup (installed to `/usr` namespace by default).
Remove the default `config.h`, a new one will be created from `config.def.h` when compiling.

Enter the following command to build and install st (as root if needed).
```
make clean install
```


### Running st

If you didn't install with `make clean install` you must compile the st terminfo entry
with the following command:
```
tic -sx st.info
```

See the man page for additional details.


### Credits

Based on Aurélien APTEL <aurelien dot aptel at gmail dot com> bt source code.
