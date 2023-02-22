#include "shell.h"


char *_getenv(const char *name)
{
	char *var = NULL, *value;
	char *copy = NULL;
	int i;

	copy = strdup(name);

	i = 0;
	while (*(environ + i) != NULL)
	{
		var = strtok(environ[i], "=");
		value = strtok(NULL, "=");
		if (_strcmp(var, copy) == 0)
		{
			free(copy);
			return (value);
		}
		i++;
	}
	free(copy);
	return (NULL);
}


