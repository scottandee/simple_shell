#include "shell.h"

char *_strtok(char *str, const char *delim)
{
	static char *buffer = NULL;

	if (buffer == NULL)
	{
		buffer = str;
	}
	if (*buffer == '\0')
	{
		return (NULL);
	}

	char *token = buffer;

	while (*buffer != '\0' && *buffer != *delim)
	{
		buffer += 1;
	}
	if (buffer != NULL)
	{
		*buffer = '\0';
		buffer += 1;
	}
	return (token);
}

size_t _strlen(const char *s)
{
	size_t len = 0;
	int i = 0;

	while (s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char *_strcpy(char *dest, const char *src)
{
	int i = 0;
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
