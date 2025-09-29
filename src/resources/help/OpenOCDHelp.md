## OpenOCD debug mode
+ OpenOCD is an open-source tool used for debugging, programming, and testing embedded systems.
+ With built-in front-end GDB, Seer combines with OpenOCD, helping you debug microcontroller or event Linux embedded system easier than ever.
+ This geature is an attempt to replace expensive Trace32 with free open-source Seer and affordable debugger.
### Input parameters
1. On `OpenOCD -> Main` tab, you need to specify or path to openocd executable and command to OpenOCD.
2. On `OpenOCD -> GDB Multiarch` tab, you need to specify path to gdb-multiarch on your system.
3. If you symbol file is built inside a docker, then you need to fill in the absolute path on your system to build folder and relative path inside docker.
4. Lastly, on `OpenOCD -> Kernel` tab, specify path to your kernel symbol file, and path to kernel source code. 
### Debug Module on Init
`Debug Module on Init` is a feature of Seer supports you debugging a kernel module at the very beginning of `_init` function. This feature mimics Trace32 `Module Debugging` feature
