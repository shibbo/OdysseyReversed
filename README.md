# OdysseyReversed
A project that documents the structures and classes in Super Mario Odyssey. This repo contains header files that contain information on the game, such as classes, namespaces, static functions, static variables, and more.

# Using OdysseyReversed
As of 3/3/2019, you can now compile code using these headers and make your own custom code! This requires libnx binaries to be placed in *lib*, and for *devkitA64* to be installed and in your $PATH. Once that is done, simply run *make* and it should output an NSO. Rename this to subsdk1, apply the below patch to branch to your code, and enjoy!

Use this IPS patch to enable a branch to your custom code.
```
@little-endian
@nsobid-F5DCCDDB37E97724EBDBCCCDBEB965FF
@flag offset_shift 0x100
# Super Mario Odyssey 1.2.0

// branch to custom code
@enabled
00774B10 F37D9614
```

As the comments imply, this repo only supports *Super Mario Odyssey 1.2*.

# Credits
0CBH0 - nsnsotool
Khangaroo - Custom code templating
libnx - Makefile creation
Retr0id - Linker creation