#include "shell.h"

/**
  * main - this is the entry point function
  * Return: Always 0
  */
int main(void)
{
	char *input_text, *buffer = NULL;
	int argc, built = 0;
	char **tokens;
	int status = 1;

	while (status)
	{
		argc = 0;
		tokens = NULL;
		input_text = read_input();
		if (input_text == NULL || strcmp(input_text, "\n") == 0)
		{
			free(input_text);
			return (1);
		}
		tokens = split_input(input_text, &argc);
		if (_strcmp(tokens[0], "exit") == 0 && argc == 1)
		{
			free_tokens(tokens, argc);
			return (0);
		}

		built = get_builtin_func(tokens);
		if (built == -1)
		{
			buffer = tokens[0];
			tokens[0] = find_path(tokens[0]);
			if (_strcmp(tokens[0], buffer) != 0)
			{
				free(buffer);
			}
			status = execute(tokens);
		}

		free_tokens(tokens, argc);
	}
	return (0);
}
