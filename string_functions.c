#include "shell.h"

/**
 * _strlen - function that returns the length of a string
 * @s: var received
 * Return: Always 0.
 */

int _strlen(char *s)

{

	int n;

	while (s[n])
	{
		n++;
	}
	return (n);
}

/**
 * _strcmp - compare two strings
 *
 * @s1: parameter
 * @s2: parameter
 *
 * Return: difference of first unmatched char in ascii values
 */

int _strcmp(char *s1, char *s2)
{
	int x, ret;

	for (x = 0; s1[x] != '\0' && s2[x] != '\0'; x++)
	{
		if (s1[x] != s2[x])
		{
			ret = s1[x] - s2[x];
			break;
		}
		else
			ret = 0;
	}
	return (ret);
}

/**
 * _strncmp - compare the first n bytes of two strings
 *
 * @s1: parameter
 * @s2: parameter
 * @n: number of bytes
 *
 * Return: difference of first unmatched char in ascii values
 */

int _strncmp(char *s1, char *s2, int n)
{
	int x, ret;

	for (x = 0; (s1[x] != '\0' || s2[x] != '\0') && x < n; x++)
	{
		if (s1[x] != s2[x])
		{
			ret = s1[x] - s2[x];
			break;
		}
		else
			ret = 0;
	}
	return (ret);
}

/**
 * _strdup - copy string, return pointer to it
 *
 * @str: original string
 *
 * Return: pointer to duplicated string, NULL otherwise
 */

char *_strdup(char *str)
{
	int i, j;
	char *new;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != 0; i++)
	{
	}

	new = malloc((sizeof(char) * i) + 1);

	if (new == NULL)
		return (NULL);

	for (j = 0; j != i; j++)
		new[j] = str[j];

	return (new);
	free(new);
}
