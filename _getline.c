#include "main.h"

/**
 * get_line - the path into which user's commands are stored
 * @str: the string variable i.e the buffer
 * Return: the no. of characters
 */
size_t get_line(char **str)
{
	ssize_t j = 0, s = 0, u = 0, w = 0, p = 0;
	char buff[1024];

	while (w == 0 && (j = read(STDIN_FILENO, buff, 1024 - 1)))
	{
		if (j == -1)
			return (-1);

		buff[j] = '\0';

		p = 0;
		while (buff[p] != '\0')
		{
			if (buff[p] == '\n')
				w = 1;
			p++;
		}

		if (u == 0)
		{
			j++;
			*str = malloc(sizeof(char) * j);
			*str = _strcpy(*str, buff);
			s = j;
			u = 1;
		}
		else
		{
			s += j;
			*str = _strcat(*str, buff);
		}
	}
	return (s);
}
