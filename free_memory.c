#include "shell.h"


/**
  * free_memory - free double pointer up to NULL
  *
  * @ptr: double pointer to free
  */

void free_memory(char **ptr)
{
	int i;

	for (i = 0; ptr[i] != NULL; i++)
	{
		free(ptr[i]);
	}
	free(ptr);
}

/**
 * _realloc - reallocate a memory block
 *
 * @ptr: pointer to old_size
 * @old_size: allocated size
 * @new_size: expected size
 * Return: pointer to new_size, NULL otherwise
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (old_size == new_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size < old_size)
		free(ptr);

	free(ptr);
	ptr = malloc(new_size);

	return (ptr);
}
