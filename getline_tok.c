#include "shell.h"

/**
 * _getnewline - check new line and return exit code
 *
 * @string: received string
 * @ret: return of getline function
 *
 * Return: exit code
 */

int _getnewline(char *string, int ret)
{
	if (ret == -1) /* if error and EOF for ctrl+d */
	{
		if (ret == EOF)
		{
			free(string);
			return (0); /* exit with no errors */
		}
		perror("Error");
		free(string);
		return (-1); /* exit with error */
	}
	if (string[0] == '\n')
	{
		free(string);
		return (3); /* loop again */
	}
	if (_strcmp(string, "exit\n") == 0)
	{
		free(string);
		return (0); /* exit with no errors */
	}
	if (_strcmp(string, "env\n") == 0)
	{
		free(string);
		_printenv();
		return (3); /* loop again */
	}
	return (1); /* execute string */
}

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
	int i = 0, j = 0, toklen = 0;
	char **toks = NULL;

	toks = malloc(sizeof(char *) * 32);

	j = _strlen(string);
	string[j - 1] = '\0';

	token = strtok(string, " ");
	while (token != NULL)
	{
		toklen = _strlen(token);
		toks[i] = malloc(toklen + 1);
		_strcpy(toks[i], token);
		token = strtok(NULL, " ");
		i++;
	}
	toks[i] = NULL;
	return (toks);
}
