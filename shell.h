#ifndef SHELL_H
#define SHELL_H

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* environment_functions */
void _printenv(void);
char *_getenv(char *name);

/* functions to help main */
char **tokenize(char *string);
char *_getnewline(char *string, int ret);
void _prompt(void);
void free_memory(char **ptr);

/* string_functions */
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
#endif
