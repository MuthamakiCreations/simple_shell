#include "main.h"

/**
 * free_double_ptr - free memmory allocated arrays
 * @str: strings in the array
 */
void free_double_ptr(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
