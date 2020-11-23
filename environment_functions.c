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

/**
  * findcom - find command in the path
  *
  * @value: value of variable PATH
  * @string: string to check
  *
  * Return: path of command, original string (first token) if not found
  */

char *findcom(char *string)
{
	char *value = NULL; /* path */
	char *thingie = "/", *stok = NULL, *ptok = NULL, *find = NULL;
	struct stat buf;

	find = malloc(1024);
	value = _getenv("PATH");
	stok = strtok(string, " "); /* we only need 1st token */
	if (stat(stok, &buf) == 0)
		return (stok);

	ptok = strtok(value, ":");
	while (ptok != NULL)
	{
		find = strcat(find, ptok);
		find = strcat(find, thingie);
		find = strcat(find, stok);
		if (stat(find, &buf) == 0)
			return (find);
		ptok = strtok(NULL, ":");
	}
	return (stok);
}
