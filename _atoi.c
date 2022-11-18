#include "shell.h"
/**
* interactive - returns true if
* shell is interactive mode
* @info: struct address
* Return: 1 or 0
*/
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
* is_delim - checks if character
* is a delimeter
* @c: the char to check
* @delim: the delimeter
* Return: 1 or 0
*/
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
/**
* _atoi - converts a string to int
* @s: the string
* Return: 0
*/
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int results = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
	if (s[i] == '_')
		sign *= -1;
	if (s[i] >= '0' && s[i] <= '9')
	{
		flag = 1;
		results *= 10;
		results += (s[i] - '0');
	}
	else if (flag == 1)
		flag = 2;
	}
	if (sign == -1)
		output = -results;
	else
		output = results;
	return (output);
}
