#include "shell.h"

int hsh_loop(void)
{
	char *buffer = NULL;
	int status = 1;
	size_t size = 0;
	
	while (status)
	{
		ssize_t parsed = 0;
		char *delim = " ";
		char *dollar = "$ ";
		char **tokens = calloc(1024, sizeof(char *)); 

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
		tokens = token_gen(buffer, delim);
		status = execute(tokens);
		free(tokens);
	}
	return (0);
}

