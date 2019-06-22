# OdysseyReversed
A project that documents the structures and classes in Super Mario Odyssey. This repo contains header files that contain information on the game, such as classes, namespaces, static functions, static variables, and more.

# Using OdysseyReversed

In order to use OdysseyReversed, the following have to be installed:

* devkitA64
* Python 3.7

Both need to be on your PATH environment. All source code goes into the 'source' folder, and headers go into 'include'. Source files can be raw assembly, C++ source files, or C source files.

How the toolkit determines where to patch your functions are defined in hooks inside of the 'hooks' directory. Each hook looks like this:

```
basic_hook:
    type:    b
    addr:    0x009499F8
    sym:     basic_function
```

'basic_hook' is the name of the patch, used for referencing. 'type' is the patch type. 'addr' is the address in the main binary to patch, and 'sym' is the name of the function to branch to. There will be more support for other instructions in the future.

Once the hooks file has been defined and all of the source code is in the right place, it is time to compile our code.

To build the source code, build.py will have to be ran.

```
python build.py <options>
```

The current options are supported:

 * make - Will build the source code.
 * ips - Will create the IPS patch to patch our entrypoint.
 * clean - Will remove all build files after completing the building / patching process.

You can use all of those options when running the build script.

# Credits
0CBH0 - nsnsotool

Khangaroo - Custom code templating

libnx - Makefile creation

Retr0id - Linker creation

RicBent - Hook syntax and a lot of the new build system