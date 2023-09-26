#include "shell.h"

/**
  * main - this is the entry point function
  * Return: Always 0
  */

int main(void)
{
	char *input_text, *copy, **tokens;
	int argc, built = 0, status = 0;

	while (1)
	{
		argc = 0;
		tokens = NULL;
		input_text = read_input();
		if (input_text == NULL)
		{
			free(input_text);
			break;
		}
		copy = malloc(sizeof(char) * (_strlen(input_text) + 1));
		strcpy(copy, input_text);
		if (strtok(copy, " \n") == NULL)
		{
			free(copy);
			free(input_text);
			continue;
		}
		free(copy);
		tokens = split_input(input_text, &argc);
		if (_strcmp(tokens[0], "exit") == 0)
		{
			if (argc == 2)
				status = exit_shell(tokens);
			free_tokens(tokens, argc);
			return (status);
		}
		built = get_builtin_func(tokens);
		if (built == -1)
		{
			status = execute(tokens);
		}
		free_tokens(tokens, argc);
	}
	return (0);
}
