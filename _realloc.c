#include "main.h"

/**
 * _realloc - reallocates the memory
 * @ptr: the pointer to the previously allocated memory
 * @old_size: the old allocated size
 * @new_size: the new size to be realloocated
 * Return: the pointer to new_size
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *q;
	unsigned int j;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		q = malloc(new_size);
		if (q == NULL)
			return (NULL);
		else
			return (q);
	}

	q = malloc(new_size);
	if (q == NULL)
		return (NULL);

	for (j = 0; j < old_size && j < new_size; j++)
		*((char *)q + j) = *((char *)ptr + j);
	free(ptr);

	return (q);
}
