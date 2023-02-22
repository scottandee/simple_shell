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
	char *dollar = "$ "/*buffer_lead, *buffer_lag*/;
	int read;

	write(STDOUT_FILENO, dollar, 2);
	read = getline(&buffer, &size, stdin);
	/*buffer_lead = removeLeading(buffer);
	buffer_lag = removeLagging(buffer_lead);*/
	trimleadingandTrailing(buffer);
	if (read == -1)
	{
		free(buffer);
		return (NULL);
	}
	/*free(buffer);
	free(buffer_lead);*/
	return (buffer);
}
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
char *removeLagging(char *str)
{
	int  idx = 0, j, k = 0;
	char *edit = NULL;

	while (str[idx] != ' ' || str[idx] != '\t' || str[idx] != '\n')
	{
		idx++;
	}
	edit = malloc(sizeof(char) * idx);
	for (j = 0; str[j] != '\0'; j++)
	{
		if (str[j] != ' ')
		{
			edit[k] = str[j];
			k++;
		}
	}
	edit[k] = '\0';
	return (edit);
}
void trimleadingandTrailing(char *s)
{
	int  i,j;

	for(i=0;s[i]==' '||s[i]=='\t';i++);

	for(j=0;s[i];i++)
	{
		s[j++]=s[i];
	}
	s[j]='\0';
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]!=' '&& s[i]!='\t')
				j=i;
	}
	s[j+1]='\0';
}
