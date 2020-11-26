#include <errno.h>
#include "shell.h"

/**
 * forkenize - to fork the child
 * @argv: arguments received
 * @string: string received to free it
 * @she: name of shell for errors
 * Return: exit status (0 on success)
 */

int forkenize(char **argv, char *string, char *she)

{
	pid_t child_pid;
	int status;

	if (argv[0] == NULL)
	{
		perror(she);
		free(string);
		free_memory(argv);
		return (127);
	}
	else
	{
		(void)she;
		child_pid = fork();
		if (child_pid == -1) /* check return of fork */
		{
			perror(she);
			free(string);
			free_memory(argv);
			return (126);
		}
		if (child_pid == 0) /* execute command checking for errors */
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror(she);
				free(string);
				free_memory(argv);
				exit(126);
			}
			free(string);
			free_memory(argv);
			exit(126);
		}
		else
			wait(&status);
	}
	free(string);
	free_memory(argv);
	return (0);
}
