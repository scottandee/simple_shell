#include "shell.h"

/**
  * token_gen - this function splits the input and returns an
  * array of each word of input
  * @buffer: this is the string to be split
  * @delim: this is the separator between each word to be split
  * Return: returns an array of each word of the buffer
  */
char **token_gen(char *buffer, char *delim)
{
	char **split_string = NULL;
	int i = 0, j, token_num = 0;
	char *str = malloc(sizeof(char) * _strlen(buffer)), *token;

	_strcpy(str, buffer);
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			token_num++;
		i++;
	}
	token_num++;
	split_string = malloc(sizeof(char *) * (token_num + 1));

	for (j = 0; j < token_num; j++)
	{
		if (j == 0)
		{
			token = strtok(str, delim);
			split_string[j] = malloc(sizeof(char) * (_strlen(token)));
			_strcpy(split_string[j], token);
		}
		else
		{
			token = strtok(NULL, delim);
			split_string[j] = malloc(sizeof(char) * (_strlen(token)));
			_strcpy(split_string[j], token);
		}
	}
	free(str);
	split_string[token_num] = NULL;
	return (split_string);
}
