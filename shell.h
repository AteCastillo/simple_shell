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
char **tokenize(char *string, char **toks);
char *_getnewline(char *string, int get);

/* string_functions */
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *str);
int _strlen(char *s);
#endif
