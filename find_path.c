#include "shell.h"

char *find_path(char *command)
{
	char *path, *temp, *path_copy, *token;
	int i, count = 0;
	struct stat st;

	if (stat(command, &st) == 0)
		return (command);
	path = getenv("PATH");
	path_copy = strdup(path);
	i = 0;
	while (*(path_copy + i) != '\0')
	{
		if (*(path_copy + i) == ':')
			count++;
		i++;
	}
	count++;
	for (i = 0; i < count; i++)
	{
		if (i == 0)
		{
			token = strtok(path_copy, ":");
		}
		else
		{
			token = strtok(NULL, ":");
		}
		temp = malloc(sizeof(char) * (_strlen(command) + _strlen(token) + 2));
		_strcpy(temp, token);
		strcat(temp, "/");
		strcat(temp, command);
		strcat(temp, "\0");
		if (stat(temp, &st) == 0)
		{
			free(path_copy);
			return (temp);
		}
	}
	free(path_copy);
	return (NULL);
}
