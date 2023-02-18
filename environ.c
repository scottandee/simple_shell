#include "shell.h"


char *_getenv(const char *name)
{
	char *var = NULL, *value = NULL;
	char *copy = NULL;
	int i;

	copy = strdup(name);

	i = 0, j = 0;
	while (*(environ + i) != NULL)
	{
		
		var = strtok(environ[i], "=");
		value = strtok(NULL, "=");
		if (strcmp(var, copy) == 0)
		{
			return (value);
		}
		i++;
	}
	return (NULL);
}


