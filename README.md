![Simple_Shell](https://pbs.twimg.com/media/Ef0CEwpXkAE2ezz?format=png&name=900x900)
# Simple_Shell
It would be great to create your own shell right? in this repository we want to show you how we build a simple_shell for our final term work at holberton school.

where we will use calls to the system that will help us get our simple_shell to have a behavior similar to a unix shell, and we will develop everything in the C language.

## Do you know what a shell is?
---------------------------------------------------------------
shell is nothing more than our portal or means to communicate with the operating system services. three types of shell:

  - Text lines (CLI, Command-Line Interface, command line interface),

![CLI](https://pbs.twimg.com/media/Ef0DdI2XsAAZnfX?format=png&name=small)

## flow chart
----
[![Lines text](https://pbs.twimg.com/media/EfrhfYWWAAEYQXM?format=jpg&name=large)](https://github.com/ronald0204/simple_shell/tree/master)
## test the operation of our simple_shell!
-----------------------------------
- Clone this repo:
 ```sh
    $ git clone https://github.com/ronald0204/simple_shell.git
```
 - Compile with
 ```sh
    $ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
- run manual
 ```sh
    $ man ./man_1_simple_shell
```
- Execute it:

```sh
    $ ./hsh
```
# Testing
-------------
- **The shell should work like this in interactive mode:**
```sh
  $./hsh
 ($)/bin/ls
 ./hsh main.c shell.c
 ($)
 ($) exit
  $
```
- **But also in non-interactive mode:**
```sh
  $ echo "/bin/ls" | ./hsh
  hsh main.c shell.c test_ls_2
  $
  $ cat test_ls_2
  /bin/ls
  /bin/ls
  $
  $ cat test_ls_2 | ./hsh
  hsh main.c shell.c test_ls_2
  hsh main.c shell.c test_ls_2
  $
```
## List of allowed functions and system calls for this project
-----------------------------
> **access** (man 2 access)
> **chdir** (man 2 chdir)
> **close** (man 2 close)
> **closedir** (man 3 closedir)
> **execve** (man 2 execve)
> **exit** (man 3 exit)
> **_exit** (man 2 _exit)
> **fflush** (man 3 fflush)
> **fork** (man 2 fork)
> **free** (man 3 free)
> **getcwd** (man 3 getcwd)
> **getline** (man 3 getline)
> **isatty** (man 3 isatty)
> **kill** (man 2 kill)
> **malloc** (man 3 malloc)
> **open** (man 2 open)
> **opendir** (man 3 opendir)
> **perror** (man 3 perror)
> **read** (man 2 read)
> **readdir** (man 3 readdir)
> **signal** (man 2 signal)
> **stat (__xstat)** (man 2 stat)
> **lstat (__lxstat)** (man 2 lstat)
> **fstat (__fxstat)** (man 2 fstat)
> **strtok** (man 3 strtok)
> **wait** (man 2 wait)
> **waitpid** (man 2 waitpid)
> **wait3** (man 2 wait3)
> **wait4** (man 2 wait4)
> **write** (man 2 write)

### File
------------------- 
**In this shell project, the following functions were utilized:**

| File | Contents |
| ------ | ------ |
| _atoi.c | Convert a string to an integer |
| _getenv.c | Function to get the PATH env |
| chek_builtin.c | Checks if the argument is a builtin |
| execute_cmd.c | Execute - function to execute, implement fork and child process |
| get_line.c | Functions get input from stdin and tokenize |
| include_path.c | Function separate the path in new strings |
| man_1_simple_shell | Simple_shell usage manual |
| print_functions.c | Standard output - character, string, prints a prompt for the shell |
| shell.h | Header file with libraries and prototypes |
| simple_shell.c | Creates a child process in which it executes the command |
| string_funtion.c | Concatenates two strings |
| tok_string.c | Function separate the string in new strings |

## Authors

 **GitHub:** [cristian-bedoya](https://github.com/cristian-bedoya)
 **Twitter:** [@crisbedbla](https://twitter.com/crisbedbla)
 **GitHub**[@ronald0204](https://github.com/ronald0204)
 **Twiitter:** [@ronald45251997](https://twitter.com/ronald45251997)
