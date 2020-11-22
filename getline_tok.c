#include "shell.h"

/*
 * _getnewline - to get new line
 *
 * @string: allocated buffer
 *
 * Return: a pointer.
 *

char *_getnewline(char *string, int ret)
{
	char *newline = "\n";
	char *exit = "exit";
	char *env = "env";

	if (ret == -1) if error and EOF for ctrl+d
	{
		if (ret == EOF)
			return (exit);
		perror("error");
		return (newline);
	}
	if (string[0] == '\n') when there is only newline in the prompt
		return (string);
	ret = _strlen(string); to remove new line at the end of the string
	string[ret - 1] = '\0';
	if (_strcmp(string, exit) == 0) to compare exit and leave the shell
		return (NULL);
	if (_strcmp(string, env) == 0) to print the enviroment variables
	{
		_printenv();
		return (newline);
	}
	return (string);
}
*/

/**
  * tokenize - load argv with string tokens
  *
  * @string: user input
  * @argv: argument vector
  *
  * Return: double pointer (argument vector)
  */

char **tokenize(char *string)
{
	char *token = NULL;
	int i = 0, j = 0;
	char **toks = NULL;

	toks = malloc(sizeof(char *) * 32);
	token = strtok(string, " ");
	while (token)
	{
		j = _strlen(token);
		toks[i] = malloc(sizeof(char) * (j + 1));
		_strcpy(toks[i], token);
		token = strtok(NULL, " ");
		i++;
	}
	toks[i] = NULL;
	return (toks);
}
