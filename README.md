# ftrace
A tiny tracer for the Linux Kernel. One can see **functions calls**, **syscalls** and **received signals**.  
Only **x86_64 architecture** is supported.
Inspired by the https://en.wikipedia.org/wiki/Ftrace .  


# How to use it ?
Clone the project and run this command to compile the program:
```sh
$> make
```

```sh
$> ./ftrace <program>
```