#include "main.h"

/**
 * _strcmp - will be used for string comparison
 * @s1: the first string
 * @s2: the second string
 * Return:if success, print 0
 */

int _strcmp(char *s1, char *s2)
{
	int j = 0;

	while (*(s1 + j) == *(s2 + j) && *(s1 + j))
		j++;

	if (*(s2 + j))
		return (*(s1 + j) - *(s2 + j));
	else
		return (0);
}
