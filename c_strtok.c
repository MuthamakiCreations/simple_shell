#include "main.h"

/**
 * c_t_size - displays number of delimeter
 * @str: shell user command typed
 * @delm: delimeter (e.g. " ");
 * Return: tokken
 */
int c_t_size(char *str, char delm)
{
	int i = 0, num_delm = 0;

	while (str[i] != '\0')
	{
		if (str[i] == delm)
		{
			num_delm++;
		}
		i++;
	}
	return (num_delm);
}


/**
 * c_str_tok - tokenizes all strings even when the string is empty
 * @str: shell user command typed
 * @delm: delimeter
 * Return: array of tokens
 * (purpose is to have command look through current directory)
 */
char **c_str_tok(char *str, char *delm)
{
	int buffsize = 0, p = 0, si = 0, i = 0, len = 0, se = 0;
	char **toks = NULL, d_ch;

	d_ch = delm[0];
	buffsize = c_t_size(str, d_ch);
	toks = malloc(sizeof(char *) * (buffsize + 2));
	if (toks == NULL)
		return (NULL);

	while (str[se] != '\0')
		se++;
	while (si < se)
	{
		len = t_strlen(str, si, d_ch);
		toks[p] = malloc(sizeof(char) * (len + 1));
		if (toks[p] == NULL)
			return (NULL);
		i = 0;
		while ((str[si] != d_ch) &&
		       (str[si] != '\0'))
		{
			toks[p][i] = str[si];
			i++;
			si++;
		}
		toks[p][i] = '\0';
		p++;
		si++;
	}
	toks[p] = NULL;
	return (toks);
}
