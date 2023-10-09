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

/**
  * free_env_list - Free up the single linked list containing
  * environment variables
  */

void free_env_list(void)
{
	envi_t *temp;

	if (envi == NULL)
	{
		return;
	}
	while (envi != NULL)
	{
		temp = envi->next;
		free(envi->name);
		free(envi->value);
		free(envi);
		envi = temp;
	}
}

/**
  * remove_env_list - Remove an environment variable from
  * singly linked list
  * @name: Name of the variable to be removed
  * Return: 0 on success
  */
int remove_env_list(char *name)
{
	envi_t *head = envi, *temp;

	while (head != NULL)
	{
		if (_strcmp(head->next->name, name) == 0)
		{
			temp = head->next;
			head->next = head->next->next;
			free(temp->name);
			free(temp->value);
			free(temp);
			break;
		}
		head = head->next;
	}
	return (0);
}

