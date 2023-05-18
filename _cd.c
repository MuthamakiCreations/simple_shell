#include "main.h"

/**
 * c_strcat - string concatenation
 * @dest: destination of the new string
 * @src: the string that will be appended
 * Return: two strings that are concatenated
 */
char *c_strcat(char *dest, char *src)
{
	int length1 = 0;
	int length2 = 0;
	int total_length = 0;
	int k = 0;

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

	k = 1;
	while (src[k] != '\0')
	{
		dest[length1] = src[k];
		length1++;
		k++;
	}
	dest[length1] = '\0';

	return (dest);
}

/**
 * c_setenv - sets custome environment
 * @env: represents the env variable
 * @name: the name of the env variable
 * @dir: the path of the directory
 * Return: if success return 0
 */
int c_setenv(list_t **env, char *name, char *dir)
{
	int l = 0, k = 0;
	char *c;
	list_t *holder;

	c = _strdup(name);
	c = _strcat(c, "=");
	c = _strcat(c, dir);
	l = find_env(*env, name);

	holder = *env;
	while (k < l)
	{
		holder = holder->next;
		k++;
	}
	free(holder->var);
	holder->var = _strdup(c);
	free(c);
	return (0);
}

/**
 * cd_only - changes the  directory
 * @env: the environment variable
 * @current: shows the current directotry
 */
void cd_only(list_t *env, char *current)
{
	char *h = NULL;

	h = get_env("HOME", env);
	c_setenv(&env, "OLDPWD", current);
	free(current);
	if (access(h, F_OK) == 0)
		chdir(h);
	current = NULL;
	current = getcwd(current, 0);
	c_setenv(&env, "PWD", current);
	free(current);
	free(h);
}
/**
 * cd_execute - change directory is executed
 * @env: the environment variable
 * @current: shows the current directotry
 * @dir: shows the path of the directory
 * @str: works out the first argument
 * @num: shows the number of the line that has error
 * Return: 0 if success and 2 when otherwise
 */
int cd_execute(list_t *env, char *current, char *dir, char *str, int num)
{
	int h = 0;

	if (access(dir, F_OK) == 0)
	{
		c_setenv(&env, "OLDPWD", current);
		free(current);
		chdir(dir);
		current = NULL;
		current = getcwd(current, 0);
		c_setenv(&env, "PWD", current);
		free(current);
	}
	else
	{
		cant_cd_to(str, num, env);
		free(current);
		h = 2;
	}
	return (h);
}

/**
 * _cd - change directory
 * @str: the string variable
 * @env: the enviromental variable
 * @num: the line number
 * Return: if success 0, otherwise 2
 */
int _cd(char **str, list_t *env, int num)
{
	char *d = NULL, *dir = NULL;
	int e = 0;

	d = getcwd(d, 0);
	if (str[1] != NULL)
	{
		if (str[1][0] == '~')
		{
			dir = get_env("HOME", env);
			dir = c_strcat(dir, str[1]);
		}
		else if (str[1][0] == '-')
		{
			if (str[1][1] == '\0')
				dir = get_env("OLDPWD", env);
		}
		else
		{
			if (str[1][0] != '/')
			{
				dir = getcwd(dir, 0);
				dir = _strcat(dir, "/");
				dir = _strcat(dir, str[1]);
			}
			else
				dir = _strdup(str[1]);
		}
		e = cd_execute(env, d, dir, str[1], num);
		free(dir);
	}
	else
		cd_only(env, d);
	free_double_ptr(str);
	return (e);
}
