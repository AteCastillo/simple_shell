#include "shell.h"

/**
 * _strlen - function that returns the length of a string
 * @s: var received
 * Return: Always 0.
 */

int _strlen(char *s)

{

	int n = 0;

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

	for (x = 0; s1[x] != '\0' || s2[x] != '\0'; x++)
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
 * _strcpy - a function that copies the string pointed to by src
 * @dest: var received
 * @src: var received
 * Return: Always 0.
 */


char *_strcpy(char *dest, char *src)
{
	int n, i; /* n if for the lenght of the string, i for iteration */

	for (n = 0; src[n] != '\0'; n++)
	{
	}

	for (i = 0; i <= n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);

}
