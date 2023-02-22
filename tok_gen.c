#include "shell.h"

/**
  * token_gen - this function splits the input and returns an
  * array of each word of input
  * @buffer: this is the string to be split
  * @delim: this is the separator between each word to be split
  * @argc: this is the number of times the strtok will work
  * Return: returns an array of each word of the buffer
  */
char **token_gen(int *argc, char *buffer, char *delim)
{
	char **split_string = NULL;
	int i = 0, j;
	char *str = malloc(sizeof(char) * strlen(buffer)), *token;

	_strcpy(str, buffer);
	while (str[i] != '\0')
	{
		if (*(str + i) == ' ')
			(*argc)++;
		i++;
	}
	(*argc)++;
	split_string = malloc(sizeof(char *) * ((*argc) + 1));

	for (j = 0; j < (*argc); j++)
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
	split_string[(*argc)] = NULL;
	return (split_string);
}
