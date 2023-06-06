#include "shell.h"

/**
  * free_tokens - this frees an array of strings(tokens)
  * @tokens: this is the array of tokens to be freed
  * @argc: this is the number of tokens in the array
  */

void free_tokens(char **tokens, int argc)
{
	int i = 0;

	for (i = 0; i < argc; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}

/**
  * read_input - this function reads input from out shell and
  * returns it
  *
  * Return: this function returns the string read on success
  * and NULL on failure
  */
char *read_input(void)
{
	char *buffer = NULL;
	size_t size = 0;
	ssize_t char_read;

	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	char_read = getline(&buffer, &size, stdin);
	if (char_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}


