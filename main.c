#include "shell.h"

/**
  * main - entry point
  *
  * Return: 0 (success), -1 otherwise
  */

int main(void)
{
	int i, status, ret; /*ret for return from getline*/
	pid_t child_pid;
	size_t size = 0;
	char **argv = NULL, *string = NULL;

	while (1) /* loop is broken by user input */
	{
		_prompt();
		ret = getline(&string, &size, stdin);
		/*	string = _getnewline(string, ret);*/
		/*		if (string == NULL)
		{
			free(string);
			break;
			}*/
		if (ret == -1)
		{
			if (ret == EOF)
			{
				free(string);
				return(0);
			}
			free(string);
			perror("error");
			return(1);
		}
		if (string[0] == '\n') /* input is just a return */
		{
			free(string);
			continue;
		}

		if (_strcmp(string, "exit\n") == 0)
			{
				free(string);
				return(0);
			}
		if (_strcmp(string, "env\n") == 0)
		{
			_printenv();
			free(string);
			continue;
		}
		ret = _strlen(string);
		string[ret - 1] = '\0';
		argv = tokenize(string); /* load argv with tokens */
		child_pid = fork();
		if (child_pid == -1) /* check return of fork */
			break;
		else if (child_pid == 0) /* execute command checking for errors */
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error");
			free(string);
			for (i = 0; argv[i] != NULL; i++)
				free(argv[i]);
			free(argv);
			break;
		}
		else
			wait(&status);
		free(string);
		for (i = 0; argv != NULL; i++)
			free(argv[i]);
		free(argv);
	}
	return (0);
}

/**
 * main - for interactive mode
 * Return: nothing
 */

void _prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(1, "($) ", 4);
}
