#include "shell.h"

/**
  * variable_sub - This function substitutes environment variables
  * for their values when detected
  * @tokens: This contains the command and arguments entered by user
  * Return: It returns the modified tokens
  */

char **variable_sub(char **tokens)
{
	int i = 1;
	char *sub;

	while (tokens[i] != NULL)
	{
		if (tokens[i][0] == '$')
		{
			sub = environ_sub(tokens[i]);
			if (sub != NULL)
			{
				tokens[i] = sub;
				break;
			}
		}
		i++;
	}
	return (tokens);
}

/**
  * environ_sub - This function calls the getenv command and
  * returns the value of the environment variable
  *
  * @var: This is the environment variable to be searched for
  * Return: The value of the environment variable if found
  */

char *environ_sub(char *var)
{
	int i = 0, length = _strlen(var);
	char *name, *value;

	name = malloc(sizeof(char) * length);

	for (i = 0; i < length; i++)
	{
		name[i] = var[i + 1];
	}

	value = _getenv(name);

	if (value != NULL)
		free(var);
	free(name);
	return (value);
}
