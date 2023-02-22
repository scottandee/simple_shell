#include "shell.h"

/**
  * _strtok - this breaks a string in zero or more non-empty strings
  * @str: this is the string to be split
  * @delim: this is the separator between the strings to be split
  * Return: On the first call, it returns the first split part
  * on subsequent calls, NULL will be put in place of the str and it'll
  * continue to return an newly broken string till it reaches the end of
  * the intitial string passed
  */
char *_strtok(char *str, const char *delim)
{
	static char *buffer;
	char *token;

	if (buffer == NULL)
	{
		buffer = str;
	}
	if (*buffer == '\0')
	{
		return (NULL);
	}

	token = buffer;
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


