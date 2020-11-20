#include "shell.h"
/**
 * _getnewline - to get new line
 *
 * @string: allocated buffer
 *
 * Return: a pointer.
 */

char *_getnewline(char *string)
{
	int get = 0;
	size_t size = 0;
	char *newline = "\n";
	char *exit = "exit";
	char *env = "env";

	get = getline(&string, &size, stdin);
	if (get == -1) /*if error and EOF for ctrl+d */
	{
		if (get == EOF)
			return (NULL);
		perror("error");
		return (newline);
	}
	if (string[0] == '\n') /*when there is only newline in the prompt*/
		return (string);
	get = _strlen(string); /*to remove new line at the end of the string */
	string[get - 1] = '\0';
	if (_strcmp(string, exit) == 0) /*to compare exit and leave the shell */
	{
		free(string);
		return (NULL);
	}
	if (_strcmp(string, env) == 0) /*to print the enviroment variables */
	{
		_printenv();
		return (newline);
	}
	return (string);
}

/**
  * tokenize - load argv with string tokens
  *
  * @string: user input
  * @argv: argument vector
  *
  * Return: double pointer (argument vector)
  */

char **tokenize(char *string, char **argv)
{
	char *token = NULL;
	int i = 0;

	token = strtok(string, " ");
	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;
	return (argv);
}
