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

## Features

 - built-in command *env*

 - execute commands with arguments

 - execute files

## Files
   Every file contains functions used to work with the main file.

- shell.h:
  header file.
- main.c

- string_funtions.c
  contains functions to work with strings:
  - _strlen - to get the length of a string
  - _strcmp - to compare two strings
  - _strncmp - to compare two strings with a certain number of bytes
  - _strcpy - to copy a string contained in a variable into another variable

- getline_tok.c
  - _getnewline - to check EOF, new line, exit and env
  - _getnewline - allocates tokens and tokenize the string given as imput.

- fork.c
  - forkenize - to fork the parent program into child.

- environment_functions.c
  functions to work with environment variables:
  - _printenv - to print the current environment
  - _getenv - to get the value of the environment variable

- free_memory.c
  A function to free all argument allocations.

## Bugs

 Not known yet

## Authors

This program was written by:

- Atenea Castillo

- Micaela Percovich

As part of the foundations programme of Holberton School.
