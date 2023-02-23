#include "shell.h"
/**
  * freeArray - this frees an array of arrays
  * @arr: this is the array of strings
  */
void freeArray(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
	}
	free(arr);
}
/**
  * read_input - this reads the input entered in to the shell
  * Return: returns the string input
  */
char *read_input()
{
	size_t size = 0;
	char *buffer = malloc(size * sizeof(char));
	char *dollar = "$ ", *buffer_lead;
	int read;

	write(STDOUT_FILENO, dollar, 2);
	read = getline(&buffer, &size, stdin);
	buffer_lead = removeLeading(buffer);
	/*buffer_lag = removeLagging(buffer_lead);*/
	if (read == -1)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (buffer_lead);
}
/**
  * removeLeading -  this removes the whitespaces in front of the command
  * @str : this is the command passed
  * Return: the trimmed string
  */
char *removeLeading(char *str)
{
	int idx = 0, j, k = 0;
	char *edit = NULL;

	while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n')
	{
		idx++;
	}
	edit = malloc(sizeof(char) * (_strlen(str) - idx));
	for (j = idx; str[j] != '\0'; j++)
	{
		edit[k] = str[j];
		k++;
	}
	edit[k] = '\0';
	return (edit);
}
/**
  * removeLagging - this trims off the white space at the
  * back of the command passed
  * @str: this is the command passed
  * Return: the trimmed command
  */
char *removeLagging(char *str)
{
	int idx = 0;
	char *edit;
	size_t size = 0;

	while (str[idx] != ' ' || str[idx] != '\t' || str[idx] != '\n')
	{
		idx++;
	}
	size = idx + 1;
	edit = strndup(str, size);
	return (edit);
}
