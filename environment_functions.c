#include "shell.h"

/**
 * _printenv - print current environment
 *
 * Loop through the array of strings environ,
 * for each string count characters, print with write
 * and then print a new line
 */

void _printenv(void)
{
	extern char **environ;
	int i;
	size_t j;

	for (i = 0; environ[i] != 0; i++)
	{
		/* loop to count characters of each string */
		for (j = 0; environ[i][j] != 0; j++)
		{
		}
	write(1, environ[i], j);
	write(1, "\n", 1);
	}
}

/**
  * _getenv - get value of environment variable
  *
  * @name: name of environment function
  *
  * Return: string with values
  */

char *_getenv(char *name)
{
	extern char **environ;
	int i;
	size_t j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '='; j++)
		{
		}
		if (_strncmp(name, environ[i], j) == 0)
		{
			strtok(environ[i], "=");
			return (strtok(NULL, "="));
		}
	}
	return (NULL);
}
