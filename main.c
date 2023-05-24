#include "main.h"

/**
 * main - simple shell
 * @ac: argument count variables
 * @av: argument vectors variables
 * @env: env variables
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	prompt(env);

	return (0);
}
