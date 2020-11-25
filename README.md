<p align="center">
  <img src="https://i.imgur.com/RFMr490.jpeg">
</p>

# Our (She)ll

 Shells are usually perceived as feminine; a symbol of birth, good fortune, and resurrection.

# She

This is a simple UNIX command language interpreter.

## Compilation

All files in this repository should be compiled in the following way:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Project requirements.

- Allowed editors: vi, vim, emacs.
- All files will be compiled on Ubuntu 14.04 LTS.
- Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic.
- All your files should end with a new line.
- A README.md file, at the root of the folder of the project is mandatory.
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl.
- Your shell should not have any memory leaks.
- No more than 5 functions per file.
- All your header files should be include guarded.
- Use system calls only when you need to.

## Usage

Once executed, the compiled file will bring up a prompt that executes built-in
commands with arguments.

```bash
./hsh
($) ls -l

```
## Exit

By typing "exit" and hitting return, or by pressing Ctrl + D.
Exit options:
- For the **she** purposes, a command which exits with a zero exit status has
 succeeded. A non-zero exit status indicates  failure.
-  When  a  command  terminates  on a fatal signal N, bash uses the value of
 128+N  as the exit status.
-  If a command is not found, the child process created to execute it returns a
 status of 127.
- If a command is found but is not executable, the return status is 126.
- If  a command fails because of an error during expansion or redirection,
 the exit status is greater than zero.
- **she** builtin commands return a status of 0 (true) if successful, and
 non-zero (false) if  an  error  occurs  while they execute.  All builtins
 return an exit status of 2 to indicate incorrect usage.

## Mode

**she** can be invoked both interactively and non-interactively.
- If it is invoked with standard input not connected to a terminal, it reads
 and executes received commands in order.

Example:
```
($) echo "hello world" | ./hsh
hello world
($)
```
- If it is invoked with standard input connected to a terminal (using
 [isatty]), an *interactive* **she** is opened. When executing interactively,
 **she** displays the prompt `($) ` when it is ready to read a command.

Example:
```
($)./hsh
($)
```

## Environment:
**she** receives and copies the environment of the parent process in which
it was executed. This environment is an array of *name-value* strings
 describing variables in the format *NAME=VALUE*.

## Command Execution:

When **she** receives a command -which is a string-, this is tokenized
 into smaller strings using a space as a delimiter. The first string works as
 the command and all remaining strings are considered arguments to that
 command; **she** then procceds with a succession of actions:
- If the first character of the command is neither a backslash nor a period,
the **she** searches for it in the list of **she** builtins. If a builtin
 with that name exists, the builtin is invoked.
- If the first character of the command is neither a backslash nor a period
 builtin, **she** searches each element of the **PATH** environmental
 variable for a directory containing an executable file by that name.
- When the first character of the command is a backslash or a period, the
 **she** executes the program with any remaining given arguments in a separate
 execution environment.

## Features

 - built-in command *env*

 - execute commands with arguments

 - execute files

## Files
   Every file contains functions used to work with the main file: main.c.

- shell.h:
  header file.

- main.c:
  - _prompt - to print the prompt ($)
  - main - entry point to the she.

- string_funtions.c: contains functions to work with strings:
  - _strlen - to get the length of a string.
  - _strcmp - to compare two strings.
  - _strncmp - to compare two strings with a certain number of bytes.
  - _strcpy - to copy a string contained in a variable into another variable.
  - _strcat - to concatenate strings.

- getline_tok.c
  - _getnewline - to check EOF, new line, exit and env.
  - _tokenize - allocates tokens and tokenize the string given as imput.
  - check - to check for special characters and spaces.

- fork.c
  - forkenize - to fork the parent program into child.

- environment_functions.c: functions to work with environment variables:
  - _printenv - to print the current environment.
  - _getenv - to get the value of the environment variable.
  - findcom - to search a command in the PATH environment variable.

- free_memory.c
  - free_memory: a function to free all argument allocations.
  - _realloc: a function to reallocate memory.

## Bugs

 Not known yet

## Authors

This program was written by:

- Atenea Castillo <[AteCastillo](https://github.com/AteCastillo)>

- Micaela Percovich <[mi-kei-la](https://github.com/mi-kei-la)>

As part of the foundations programme of Holberton School.
November, 2020.

Check our blog post [here](https://2235.medium.com/she-ll-b84052490ec7).

<p align="center">
  <img src="http://www.holbertonschool.com/holberton-logo.png" alt="Holberton School logo">
</p>