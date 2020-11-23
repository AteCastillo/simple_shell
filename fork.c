#include "shell.h"

/**
 * forkenize - to fork the child
 * @argv: arguments received
 * @string: string received to free it
 * Return: nothing
 */

void forkenize(char **argv, char *string)

{
	pid_t child_pid;
	int status;

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
		exit (9);
	}
	else
		wait(&status);

	free(string);
	free_memory(argv);
}
