#include "shell.h"

/**
  * main - entry point
  *
  * Return: 0 (success), -1 otherwise
  */

int main(void)
{
	int status, ret; /*ret for return from getline*/
	pid_t child_pid;
	size_t size = 0;
	char **argv = NULL, *string;

	while (1) /* loop is broken by user input */
	{
		string = NULL;
		_prompt();
		ret = getline(&string, &size, stdin);
		if (ret == -1)
		{
			if (ret == EOF)
			{
				free(string);
				break;
			}
			free(string);
			perror("Error");
			break;
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
			free(string);
			_printenv();
		}

		argv = tokenize(string); /* load argv with tokens */
		child_pid = fork();
		if (child_pid == -1) /* check return of fork */
		{
			perror("Error");
			exit(8);
		}
		if (child_pid == 0) /* execute command checking for errors */
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error");
			free(string);
			free_memory(argv);
			return (0);
		}
		else
			wait(&status);

		free(string);
		free_memory(argv);
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
