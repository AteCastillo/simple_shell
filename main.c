#include "shell.h"

/**
  * main - entry point
  *
  * Return: 0 (success), -1 otherwise
  */

int main(void)
{
	int i, status, ret /*, fd = 0, a */;
	pid_t child_pid;
	size_t size = 0;
	char **argv = NULL, *string = NULL;

	while (1) /* loop is broken by user input */
	{
/*		a = isatty(fd);
		if (a == 1)
*/			write(1, "($) ", 4);
		ret = getline(&string, &size, stdin);
		string = _getnewline(string, ret);
		if (string == NULL) /* check for EOF */
			break;
		else if (string[0] == '\n') /* input is just a return */
			continue;
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
	}
/*	free(string);
	for (i = 0; argv != NULL; i++)
		free(argv[i]);
*/	return (0);
}
