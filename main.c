#include "shell.h"

/**
  * main - entry point
  *
  * Return: 0 (success), -1 otherwise
  */

int main(void)
{
	int ret; /*ret for return from getline*/
	size_t size = 0;
	char **argv = NULL, *string;

	while (1) /* loop is broken by user input */
	{
		string = NULL;
		_prompt();
		ret = getline(&string, &size, stdin);
		argv = tokenize(string); /* load argv with tokens */
		forkenize(argv, string);
	}
	return (0);
}

/**
 * _prompt - for interactive mode
 * Return: nothing
 */

void _prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(1, "($) ", 4);
}
