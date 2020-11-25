#include <errno.h>
#include "shell.h"

/**
 * forkenize - to fork the child
 * @argv: arguments received
 * @string: string received to free it
 * Return: nothing
 */

int forkenize(char **argv, char *string, char *she)

{
	pid_t child_pid;
	int status, x = 0;

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
			perror("Error");
			return (126);
		}
		if (child_pid == 0) /* execute command checking for errors */
		{
			x = execve(argv[0], argv, NULL);
			if (x == -1)
			{
				perror(she);
				exit(126);
			}
			free(string);
			free_memory(argv);
			exit(0);
		}
		else
			wait(&status);
	}
	free(string);
	free_memory(argv);
	return (0);
}
