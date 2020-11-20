#include "shell.h"

/**
  * main - entry point
  *
  * Return: 0 (success)
  */

int main(void)
{
	int i, status, ret;
	size_t size = 0;
	pid_t child_pid;
	char **argv = NULL, **toks = NULL, *string = NULL;

	/*string = malloc(sizeof(char) * ; memory assignations */
	toks = malloc(sizeof(char *) * 32); /* 512 bytes total */
	for (i = 0; i < 32; i++)
		toks[i] = NULL;
	while (1) /* loop is broken by user input */
	{
		write(1, "($) ", 4);
		ret = getline(&string, &size, stdin);
		string = _getnewline(string, ret);
		if (string == NULL) /* check for EOF */
			break;
		else if (string[0] == '\n') /* user hit return without any other input */
			continue;
		argv = tokenize(string, toks); /* load argv with tokens */
		child_pid = fork();
		if (child_pid == -1) /* check return of fork */
			continue;
		else if (child_pid == 0) /* execute command checking for errors */
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error");
			break;
		}
		else
			wait(&status);
	}
	free(string); /* free memory */
	for (i = 0; i < 32; i++)
		free(toks[i]);
	free(toks);
	return (0);
}
