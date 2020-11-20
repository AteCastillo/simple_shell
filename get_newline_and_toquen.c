#include "shell.h"
/**
 * _getnewline - to get new line
 *
 * Return: a pointer.
 */

char * _getnewline(char *string)
{
	int get;
	size_t size = 0;
	char *newline = "\n";

	get = getline(&string, &buffer, stdin);
	if (get == -1) /*if error and EOF for ctrl+d */
	{
		if (get == EOF)
			return(NULL);
		perror("error");
		return(newline);
	}
	if (string[0] == "\n") /*when there is only newline in the prompt*/
		return (string);
	get = _strlen(string); /*to remove new line at the end of the string */
	string[i-1] = '\0';
	if (strcmp(string, "exit") == 0) /*to compare exit and leave the shell */
	{
		return (NULL);
	}
	if (strcmp(string, "env") == 0) /*to print the enviroment variables */
	{
		_printenv();
		return (newline);
	}
	return (string);
}

char **tokenize(char *string, char **argv)
{
	char *token;
	int i = 0;

	token = strtok(string, " ");
	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;
	return (argv);

}
