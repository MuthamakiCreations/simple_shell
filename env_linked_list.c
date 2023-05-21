#include "main.h"

/**
 * env_linked_list - environmental variables for a linked list
 * @env: environmental variables for shell
 * Return: 1
 */
list_t *env_linked_list(char **env)
{
	list_t *head;
	int i = 0;

	head = NULL;
	while (env[i] != NULL)
	{
		add_end_node(&head, env[i]);
		i++;
	}
	return (head);
}

/**
 * _env - prints the environmental variables
 * @str: shell command for user
 * @env: environmental variables for the shell
 * Return: 0 on pass
 */
int _env(char **str, list_t *env)
{
	free_double_ptr(str);
	print_list(env);
	return (0);
}
