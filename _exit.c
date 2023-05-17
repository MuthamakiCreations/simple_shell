#include "main.h"

/**
 * c_atoi - converts ascii to an intiger
 * @s: represents a string
 * Return: print number if success, and  -1 otherwise
 */
int c_atoi(char *s)
{
	int x = 0;
	unsigned int number = 0;

	while (s[x] != '\0')
	{
		if (s[x] >= '0' && s[x] <= '9')
			number = number * 10 + (s[x] - '0');
		if (s[x] > '9' || s[x] < '0')
			return (-1);
		x++;
	}
	return (number);
}

/**
 * __exit - exits the program
 * @str: this is the command from the user
 * @env: represents the environmental variable
 * @num: shows the number to print the error
 * @command: the command is freed
 * Return: 0 if success and 2 if otherwise
 */
int __exit(char **str, list_t *env, int num, char **command)
{
	int j = 0;

	if (str[1] != NULL)
		j = c_atoi(str[1]);

	if (j == -1)
	{
		illegal_number(str[1], num, env);
		free_double_ptr(str);
		return (2);
	}
	free_double_ptr(str);
	free_linked_list(env);
	if (command != NULL)
		free_double_ptr(command);
	exit(j);
}
