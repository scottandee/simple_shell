#include "shell.h"

/**
  * split_input - this function splits the input received by the
  * getline function into tokens
  *
  * @input_text: this is the input text to be split into tokens
  * @argc: this is the number of tokens that are to be split
  * Return: On sucess, the functions returns an array of string
  * containing the tokens
  */

char **split_input(char *input_text, int *argc)
{
	char *copy, *p;
	int i = 0;
	char **arr;

	copy = malloc(sizeof(char) * (_strlen(input_text) + 1));
	_strcpy(copy, input_text);

	(*argc) = 0;
	p = strtok(input_text, " \n");
	(*argc)++;

	while (p != NULL)
	{
		p = strtok(NULL, " \n");
		if (p != NULL)
		{
			(*argc)++;
		}
	}

	arr = malloc(((*argc) + 1) * sizeof(char *));

	p = strtok(copy, " \n");
	arr[i] = malloc(sizeof(char) * (_strlen(p) + 1));
	_strcpy(arr[i], p);

	for (i = 1; i < (*argc); i++)
	{
		p = strtok(NULL, " \n");
		arr[i] = malloc(sizeof(char) * (_strlen(p) + 1));
		_strcpy(arr[i], p);
	}
	arr[(*argc)] = NULL;
	free(input_text);
	free(copy);
	return (arr);
}

char **commands(char *input_text)
{
	char *copy, *p;
	int i = 0, argc;
	char **arr;

	copy = malloc(sizeof(char) * (_strlen(input_text) + 1));
	_strcpy(copy, input_text);

	argc = 0;
	p = strtok(input_text, ";");
	argc++;

	while (p != NULL)
	{
		p = strtok(NULL, ";");
		if (p != NULL)
		{
			argc++;
		}
	}

	arr = malloc((argc + 1) * sizeof(char *));

	p = strtok(copy, ";");
	arr[i] = malloc(sizeof(char) * (_strlen(p) + 1));
	_strcpy(arr[i], p);

	for (i = 1; i < argc; i++)
	{
		p = strtok(NULL, ";");
		arr[i] = malloc(sizeof(char) * (_strlen(p) + 1));
		_strcpy(arr[i], p);
	}
	arr[argc] = NULL;
	free(input_text);
	free(copy);
	return (arr);
}
