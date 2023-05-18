#include "main.h"

/**
 * c_exit - all commands get freed before it exits
 * @str: variable for the string i.e user's commands
 * @env: the environment variable
 */
void c_exit(char **str, list_t *env)
{
	free_double_ptr(str);
	free_linked_list(env);
	_exit(0);
}

/**
 * _execve - executes the commands in the shell
 * @s: the user's command
 * @env: represents the environment variable
 * @num: the number of the line
 * Return: if success, return 0
 */
int _execve(char **s, list_t *env, int num)
{
	char *hd;
	int st = 0, u = 0;
	pid_t pid;

	if (access(s[0], F_OK) == 0)
	{
		hd = s[0];
		u = 1;
	}
	else
		hd = _which(s[0], env);
	if (access(hd, X_OK) != 0)
	{
		not_found(s[0], num, env);
		free_double_ptr(s);
		return (127);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(hd, s, NULL) == -1)
			{
				not_found(s[0], num, env);
				c_exit(s, env);
			}
		}
		else
		{
			wait(&st);
			free_double_ptr(s);
			if (u == 0)
				free(hd);
		}
	}
	return (0);
}
