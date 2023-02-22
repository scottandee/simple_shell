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
	char *dollar = "$ ";
	int read;

	write(STDOUT_FILENO, dollar, 2);
	read = getline(&buffer, &size, stdin);
	if (read == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
