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
