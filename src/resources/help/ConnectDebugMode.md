## Connect debug mode

### Introduction

This mode allows Seer to debug a local or remote process that was started with gdbserver (or other gdb servers).

Typically, the gdbserver starts the process and interrupts it before anything happens. It then waits for
something to connect to it. When Seer connects with it, the process is ready to continue executing.

### Requirements
In this mode, Seer needs:

* Optional executable file if the remote gdbserver/gdbstub hasn't loaded one
* Optional symbol file if the executable doesn't have debug information
* How to look for the gdbserver (machine and port)
* Remote target type when connecting to the gdbserver.
  * 'extended-remote' (default)
  * 'remote' (sometimes required if gdbserver doesn't support all commands)
* Optional enabling of gdb and gdbserver debug communication (set debug remote 1). See the gdb tab for output.
* Optional gdb commands to execute before and after Seer connects to the gdbserver

### What can you do?
In this mode, Seer will connect to the process via the gdbserver. Typically you set breakpoints first then
tell the process to continue. From this point, you can debug the process as normal (stepping and setting breakpoints, etc...)

### References

Check references for gdbserver and other gdb servers.

* gdbserver
* valgrind vgdb
* servers for embedded development

