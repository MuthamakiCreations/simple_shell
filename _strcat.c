#include "main.h"

/**
 * _strcat - this concatenates the strings
 * @dest: the string of the destination
 * @src: the new string
 * Return: the string concatenation
 */
char *_strcat(char *dest, char *src)
{
	int length1 = 0;
	int length2 = 0;
	int total_length = 0;
	int l = 0;

	while (dest[length1] != '\0')
	{
		length1++;
		total_length++;
	}
	while (src[length2] != '\0')
	{
		length2++;
		total_length++;
	}

	dest = _realloc(dest, length1, sizeof(char) * total_length + 1);

	while (src[l] != '\0')
	{
		dest[length1] = src[l];
		length1++;
		l++;
	}
	dest[length1] = '\0';

	return (dest);
}
