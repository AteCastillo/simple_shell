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
	char **argv, *string;
	size_t size = 0;

	/* memory assignations */
	string = malloc(sizeof(char) * 512);
	argv = malloc(sizeof(char *) * 64);
	for (i = 0; i < 64, i++) /* assign memory to argv pointers */
		argv[i] = malloc(sizeof(char) * 64);

	while (1) /* loop is broken by user input */
	{
		string = _get_newline(string);

		if (string == NULL) /* check for EOF */
		{
			write(1, "\n", 1);
			break;
		}
		else if (string[0] == '\n') /* user hit return without any other input */
		{
			write(1, "\n", 1);
			continue;
		}

		argv = tokenizer(string); /* load argv with tokens */

		child_pid = fork()

		if (child_pid == -1); /* check return of fork */
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

	/* free all memory */
	free(string);
	for (i = 0; i < 64; i++)
		free(argv[i]);
	free(argv);

	return (0);
}
