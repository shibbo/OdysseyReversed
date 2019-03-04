# OdysseyReversed
A project that documents the structures and classes in Super Mario Odyssey. This repo contains header files that contain information on the game, such as classes, namespaces, static functions, static variables, and more.

# Using OdysseyReversed
As of 3/3/2019, you can now compile code using these headers and make your own custom code! This requires libnx binaries to be placed in *lib*, and for *devkitA64* to be installed and in your $PATH. Once that is done, simply run *make* and it should output an NSO. Rename this to subsdk1, apply the below patch to branch to your code, and enjoy!

Before you can use the IPS patch to run your code, you have to figure out where to patch. This can vary based on code size, so you want to check the symbol map of your compiled code to figure out the offset. If our function name we used as the entrypoint is "hook_init()", we woudl find it in the generated .map file in _build_.

```
 .text._Z9hook_initv
                0x00000000000002dc       0x1c main.o
                0x00000000000002dc                hook_init()
```

The value we need is 0x2DC.

And to figure out the offset to jump to, use this formula for Odyssey 1.2.0, where *offset* is the value from above:
```
0x2D14000 + offset - 0x774B10
```

Using the output from the formula above, we simple convert a branch instruction to it to ARM:
```
B #0x259F7CC = F37D9614
```

The value will then be branched to at 0x774B10 in the executable, which is the earliest possible entrypoint for our code.

```
@little-endian
@nsobid-F5DCCDDB37E97724EBDBCCCDBEB965FF
@flag offset_shift 0x100
# Super Mario Odyssey 1.2.0

// branch to custom code
@enabled
00774B10 YOURVALUE
```

As the comments imply, this repo only supports *Super Mario Odyssey 1.2.0*.

# Credits
0CBH0 - nsnsotool

Khangaroo - Custom code templating

libnx - Makefile creation

Retr0id - Linker creation