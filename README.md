# Simple Shell Project

![](https://assets.website-files.com/6105315644a26f77912a1ada/610540e8b4cd6969794fe673_Holberton_School_logo-04-04.svg)

![Shell Logo](https://imgur.com/atBcX52.jpg)

In computing, a shell is a computer program which exposes an operating system's services to a human user or other programs. In general, operating system shells use either a command-line interface (CLI) or graphical user interface (GUI), depending on a computer's role and particular operation. It is named a shell because it is the outermost layer around the operating system.

## Requirements

-   Allowed editors:  `vi`,  `vim`,  `emacs`
-   Files will be compiled on Ubuntu 20.04 LTS using  `gcc`, using the options  `-Wall -Werror -Wextra -pedantic -std=gnu89`
-   The files will end with a new line
-   The code use the  `Betty`  style. It will be checked using  [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl")  and  [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl "betty-doc.pl")
-   The program should not have any memory leaks
-   No more than 5 functions per file
-   The header files should be include guarded
-   Usage system calls only when you need to ([why?](https://intranet.hbtn.io/rltoken/StgX3y26fwPNV_DqlZLErw "why?"))

### List of allowed functions and system calls

-   `access`  (man 2 access)
-   `chdir`  (man 2 chdir)
-   `close`  (man 2 close)
-   `closedir`  (man 3 closedir)
-   `execve`  (man 2 execve)
-   `exit`  (man 3 exit)
-   `_exit`  (man 2 _exit)
-   `fflush`  (man 3 fflush)
-   `fork`  (man 2 fork)
-   `free`  (man 3 free)
-   `getcwd`  (man 3 getcwd)
-   `getline`  (man 3 getline)
-   `getpid`  (man 2 getpid)
-   `isatty`  (man 3 isatty)
-   `kill`  (man 2 kill)
-   `malloc`  (man 3 malloc)
-   `open`  (man 2 open)
-   `opendir`  (man 3 opendir)
-   `perror`  (man 3 perror)
-   `read`  (man 2 read)
-   `readdir`  (man 3 readdir)
-   `signal`  (man 2 signal)
-   `stat`  (__xstat) (man 2 stat)
-   `lstat`  (__lxstat) (man 2 lstat)
-   `fstat`  (__fxstat) (man 2 fstat)
-   `strtok`  (man 3 strtok)
-   `wait`  (man 2 wait)
-   `waitpid`  (man 2 waitpid)
-   `wait3`  (man 2 wait3)
-   `wait4`  (man 2 wait4)
-   `write`  (man 2 write)

## Usage

### Interactive

The simple shell usage is as follows:

`Command` + `Flags` + `Args`

Where **Command** is always required in comparison to the **Flags** or **Args** to execute a procedure.

 Some examples:

`ls -l /usr/local/`

![Example](https://imgur.com/w4UTsSc.jpg)

### Non-Interactive

We can avoid the usage of the graphical interface of this shell using it with a bash script or using it through another interface like by defect Linux shell.

An example:

`echo /bin/ls -l | ./simple_shell`

![Non interactive](https://imgur.com/bbF13Ql.jpg)

## Flow Chart

![Shell Flowchart](https://github.com/Ragnar9902/simple_shell/blob/f0fda0a67763cb0ae5f190dfec0f7dc2b6fc045c/Flowchart.jpg)

## References
[Shell Computing](https://en.wikipedia.org/wiki/Shell_(computing)) Article on Wikipedia.

[Man Pages](https://man7.org/linux/man-pages/) in Shell command or in `Man7.org`

[Tutorial - Write a Shell](https://brennan.io/2015/01/16/write-a-shell-in-c/) in C by Stephen Brennan


## Authors

### Jesús Macías:

**GitHub Account:**
`https://github.com/Ragnar9902`
**Email Account:**
`4588@holbertonschool.com`


### Marco Antonio Ordóñez:

**GitHub Account:**
`https://github.com/MaoScorpion21`
**Email Account:**
`mao7021@hotmail.com` `3917@holbertonschool.com`