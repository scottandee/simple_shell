#include "shell.h"

char **token_gen(char *buffer, char *delim)
{
	char **split_string = NULL;
	int i = 0, j, token_num = 0, len = 0;
	char *str = NULL, *token = NULL;
	str = strdup(buffer);
	len = strlen(str);
	while (str[i] != '\0')
	{
		if (*(str + i) == ' ')
			token_num++;
		i++;
	}
	token_num++;
	split_string = malloc(sizeof(char) * len);

	for (j = 0; j < token_num; j++)
	{
		if (j == 0)
		{			
			token = _strtok(str, delim);
			split_string[j] = malloc(sizeof(char) * (strlen(token)));
			split_string[j] = strdup(token);
		}
		else
		{
			token = _strtok(NULL, delim);
			split_string[j] = malloc(sizeof(char) * (strlen(token)));
			split_string[j] = strdup(token);
		}
	}
	free(str);
	split_string[token_num] = NULL;
	return (split_string);
}
