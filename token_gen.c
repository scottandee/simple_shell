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
	char **split = calloc(1024, sizeof(char *));
	int i = 0;

	split[i] = strtok(buffer, delim);
	i++;
	while (split[i])
	{
		split[i] = strtok(NULL, delim);
		i++;
	}

	/*split_string = malloc(sizeof(char *) * token_num);

	token = strtok(str, delim);

	for (i = 0; token != NULL; i++)
	{
		split_string[i] = malloc(sizeof(char) * (_strlen(token)));
		strcpy(split_string[i], token);
		token = strtok(NULL, delim);
	}*/
	split[i] = NULL;
	return (split);
}
