#include "main.h"

/**
 * t_strlen - the length of the string
 * @str: string to a token
 * @pos: position of the user's command
 * @delm: represents a delimeter
 * Return: the lenth of the token
 */
int t_strlen(char *str, int pos, char delm)
{
	int length1 = 0;

	while ((str[pos] != delm) && (str[pos] != '\0'))
	{
		pos++;
		length1++;
	}
	return (length1);
}

/**
 * t_size - the delimeter number
 * @str: the user's command
 * @delm: represents the delimeter
 * Return: the delimeter number
 */
int t_size(char *str, char delm)
{
	int j = 0, delimeter_number = 0;

	while (str[j] != '\0')
	{
		if ((str[j] == delm) && (str[j + 1] != delm))
		{
			delimeter_number++;
		}
		if ((str[j] == delm) && (str[j + 1] == '\0'))
		{
			delimeter_number--;
		}
		j++;
	}
	return (delimeter_number);
}

/**
 * ignore_delm - gnores the delimeter
 * @str: the string to be printed
 * @delm: represents the delimeter
 * Return: returns a new string
 */
char *ignore_delm(char *str, char delm)
{
	while (*str == delm)
		str++;
	return (str);
}

/**
 * _str_tok - tokenizes a string and returns an array of tokens
 * @str: user's command typed into shell
 * @delm: delimeter (e.g. " ");
 * Return: an array of tokens (e.g. {"ls", "-l", "/tmp"}
 */
char **_str_tok(char *str, char *delm)
{
	int buffsize = 0, p = 0, si = 0, i = 0, len = 0, se = 0, t = 0;
	char **toks = NULL, d_ch;

	d_ch = delm[0];
	str = ignore_delm(str, d_ch);
	buffsize = t_size(str, d_ch);
	toks = malloc(sizeof(char *) * (buffsize + 2));
	if (toks == NULL)
		return (NULL);
	while (str[se] != '\0')	/* find string ending index */
		se++;
	while (si < se)
	{
		if (str[si] != d_ch)
		{
			len = t_strlen(str, si, d_ch);
			toks[p] = malloc(sizeof(char) * (len + 1));
			if (toks[p] == NULL)
				return (NULL);
			i = 0;
			while ((str[si] != d_ch) && (str[si] != '\0'))
			{
				toks[p][i] = str[si];
				i++;
				si++;
			}
			toks[p][i] = '\0'; /* null terminate at end*/
			t++;
		}
		if (si < se && (str[si + 1] != d_ch && str[si + 1] != '\0'))
			p++;
		si++;
	}
	p++;
	toks[p] = NULL;
	return (toks);
}
