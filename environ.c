#include "shell.h"

/**
  * _getenv - this gets the environment variable passed into it
  * @name: this is the environment variable name
  * Return: this returns the value of the environment variable
  */
char *_getenv(char *name)
{
	char *var, *value, *current, *val;
	int i;

	i = 0;
	while (*(environ + i) != NULL)
	{
		current = _strdup(*(environ + i));
		var = strtok(current, "=");
		value = strtok(NULL, "=");
		val = _strdup(value);
		if (_strcmp(var, name) == 0)
		{
			free(current);
			return (val);
		}
		free(current);
		i++;
	}
	return (NULL);
}
