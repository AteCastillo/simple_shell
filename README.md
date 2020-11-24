# Simple Shell

This is a simple UNIX command interpreter.

## Compilation

All files in this repository should be compiled in the following way:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Usage

Once executed, the compiled file will bring up a prompt that executes built-in
commands with arguments.

```bash
./hsh
($) ls -l

```
Exit the program by typing "exit" and hitting return, or by pressing Ctrl + D.

**Shell** can be invoked both interactively and non-interactively.
If it is invoked with standard input not connected to a terminal, it reads and
 executes received commands in order.

Example:
```
($) echo "hello world" | ./hsh
hello world
($)
```
If it is invoked with standard input connected to a terminal (using [isatty),
an *interactive* shell is opened. When executing interactively, **shell**
 displays the prompt `($) ` when it is ready to read a command.

Example:
```
$./hsh
$
```
### Environment:
**shell** receives and copies the environment of the parent process in which
it was executed. This environment is an array of *name-value* strings
 describing variables in the format *NAME=VALUE*.

### Command Execution:

When **shell** receives a command -which is a string-, this is tokenized
 into smaller strings using a space as a delimiter. The first string works as
 the command and all remaining strings are considered arguments to that
 command; **shell** then procceds with a succession of actions:
- If the first character of the command is neither a backslash nor a period,
the shell searches for it in the list of shell builtins. If a builtin
 with that name exists, the builtin is invoked.
- If the first character of the command is neither a backslash nor a period
 builtin, **shell** searches each element of the **PATH** environmental
 variable for a directory containing an executable file by that name.
- When the first character of the command is a backslash or a period, the
 shell executes the program with any remaining given arguments in a separate
 execution environment.

## Features

 - built-in command *env*

 - execute commands with arguments

 - execute files

## Files
   Every file contains functions used to work with the main file: main.c.

- shell.h:
  header file.

- string_funtions.c: contains functions to work with strings:
  - _strlen - to get the length of a string
  - _strcmp - to compare two strings
  - _strncmp - to compare two strings with a certain number of bytes
  - _strcpy - to copy a string contained in a variable into another variable

- getline_tok.c
  - _getnewline - to check EOF, new line, exit and env
  - _getnewline - allocates tokens and tokenize the string given as imput.

- fork.c
  - forkenize - to fork the parent program into child.

- environment_functions.c: functions to work with environment variables:
  - _printenv - to print the current environment
  - _getenv - to get the value of the environment variable

- free_memory.c: a function to free all argument allocations.

## Bugs

 Not known yet

## Authors

This program was written by:

- Atenea Castillo

- Micaela Percovich

As part of the foundations programme of Holberton School.
