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
	static char *buffer = NULL;
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

/**
  * _strlen - this counts the number of characters present in a string
  * @s: this is the string to be counted
  * Return: it returns the length of the string
  */
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
/**
  * _strcpy - this copies the content of src into dest
  * @src: this is the source string that will be copied
  * @dest: this is the destination string in to which the content of src will be copied into
  * Return: it returns a pointer to the destination string
  */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/**
  * _strcat - this appends the contents of src to destination
  * @src: this is the string that will be copied from
  * @dest: this is the string that will be appended to
  * Return: this returns a pointer to the concatenated string
  */
char *_strcat(char *dest, const char *src)
{
	int i;
	int src_len = _strlen(src), dest_len = _strlen(dest);

	for (i = 0; i < src_len; i++)
	{
		dest[dest_len + i] = src[i];
	}
	return (dest);
}

/**
  * _strcmp - this compares teo strings
  * @s1: this is one of the string to be compared
  * @s2: thus is another one of the string to be compared
  * Return: returns 0 if both strings are the same
  * returns a positive value if s1 is greater than s2
  * returns a negative value if s1 is less than s2
  */

int _strcmp(char *s1, char *s2)
{
	int i, cmp, s1_len = 0;

	s1_len = _strlen(s1);

	for (i = 0; i < s1_len; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			return (cmp);
		}
	}
	return (0);
}
