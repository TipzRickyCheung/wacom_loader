# Wacom Loader

This program is written to load/unload the faulty [linuxwacom/input-wacom](https://github.com/linuxwacom/input-wacom) kernel module dynamically with the intention of using it with built-in shortcuts feature that comes in many modern desktop environments (DEs)

## Installation

To install this program, run in a terminal:

```
./build.sh install
```

The proper privileges the program requires are automatically set. It is up to the user to hook it up with their DEs' shortcut system.

## Improvements

This program should be wired up to utilities provided by your distro so that root privileges are granted correctly and cannot be used for privileage esculation.

While effort has been taken to try and secure this program, it is advised that users install this program at their own risk.

## Further read

[Original bug report thread](https://github.com/linuxwacom/input-wacom/issues/342)
