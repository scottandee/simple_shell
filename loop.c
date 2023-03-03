#include "shell.h"

int hsh_loop(void)
{
	char *buffer = NULL;
	int status = 1;
	size_t size = 0;
	
	while (status)
	{
		int i = 1;
		ssize_t parsed = 0;
		char *delim = " ", built;
		char *dollar = "$ ";
		char **tokens = calloc(1024, sizeof(char *));

		if (tokens == NULL)
		{
			free(tokens);
			return (0);
		}

		if (isatty(STDIN_FILENO))
		{
			write(1, dollar, 2);
		}
		parsed = getline(&buffer, &size, stdin);
		if (parsed == -1)
		{
			free(buffer);
			free(tokens);
			return (-1);
		}
		*(buffer + (_strlen(buffer) - 1)) = '\0';
		tokens[0] = _strtok(buffer, delim);
		tokens[1] = "gb";
		while (tokens[i])
		{
			tokens[i] = _strtok(NULL, delim);
			i++;
		}
		tokens[i] = NULL;
		built = get_builtin_func(tokens);
		if (built == 0)
		{
			status = 0;
		}
		if (built == -1)
		{
			tokens[0] = find_path(tokens[0]);
			status = execute(tokens);
		}
		free(tokens);
	}
	return (0);
}

