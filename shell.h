#ifndef SHELL_H
#define SHELL_H

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* environment_functions file */
void _printenv(void);
char *_getenv(char *name);
char *findcom(char *string);

/* functions to help main */
	/* getline file */
char **tokenize(char *string);
int _getnewline(char *string, int ret, int at);
	/* fork file */
int forkenize(char **argv, char *string);
	/* main file */
int _prompt(void);
	/* free file */
void free_memory(char **ptr);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* string_functions file */
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
#endif
