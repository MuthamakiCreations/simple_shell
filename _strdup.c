#include "main.h"

/**
 * _strdup - duplicates a string
 * @str: the string that will be  duplicated
 * Return: the location of the duplicated string
 */
char *_strdup(char *str)
{
	char *dps;
	int j, length1 = 0;

	if (str == NULL)
		return (NULL);

	while (*(str + length1))
		length1++;
	length1++;

	dps = malloc(sizeof(char) * length1);
	if (dps == NULL)
		return (NULL);

	j = 0;
	while (j < length1)
	{
		*(dps + j) = *(str + j);
		j++;
	}

	return (dps);
}
