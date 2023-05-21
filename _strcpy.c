#include "main.h"

/**
 * _strcpy - used to copy the string
 * @dest: the destination of the new string
 * @src: the string to be copied
 * Return: output similar to src
 */

char *_strcpy(char *dest, char *src)
{
	int j, length1;

	for (length1 = 0; src[length1] != '\0'; length1++)
		;

	for (j = 0; j <= length1; j++)
		dest[j] = src[j];

	return (dest);
}
