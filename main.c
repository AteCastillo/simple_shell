#include "shell.h"

/**
  * main - entry point
  *
  * Return: 0 (success), -1 otherwise
  */

int main(int argc, char **argv)
{
	int ret = 0, x = 0, at = 0; /*ret:getlin, x:getnewl, at:isatty, y:fork*/
	size_t size = 0;
	char *string, *she = NULL;

	(void)argc;
	she = argv[0];
	while (1) /* loop is broken by user input */
	{
		string = NULL;
		at = _prompt();
		ret = getline(&string, &size, stdin);
		x = _getnewline(string, ret, at);
		if (x == 0) /* exit with no errors */
			return (0);
		else if (x == -1) /* exit with error code -1 */
			return (-1);
		else if (x == 3) /* loop again */
			continue;
		argv = tokenize(string); /* load argv with tokens */
		argv[0] = findcom(argv[0]);
		forkenize(argv, string, she);
	}
	return (0);
}

/**
 * _prompt - for interactive mode
 * Return: status check
 */

int _prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(1, "($) ", 4);
		return (1);
	}
	return (0);
}
