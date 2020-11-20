#include "shell.h"

/**
  * main - entry point
  *
  * Return: 0 (success)
  */

int main(void)
{
	int i, status;
	pid_t child_pid;
	char **argv = NULL, **toks = NULL, *string = NULL, *str = NULL;

	string = malloc(sizeof(char) * 512); /* memory assignations */
	toks = malloc(sizeof(char *) * 64);
	for (i = 0; i < 64; i++)
		toks[i] = malloc(sizeof(char) * 32);
	while (1) /* loop is broken by user input */
	{
		write(1, "($) ", 4);
		str = _getnewline(string);
		if (str == NULL) /* check for EOF */
			break;
		else if (str[0] == '\n') /* user hit return without any other input */
			continue;
		argv = tokenize(str, toks); /* load argv with tokens */
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
	for (i = 0; i < 64; i++)
		free(argv[i]);
	free(argv);
	return (0);
}
