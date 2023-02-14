#include "shell.h"

char **token_gen(char *buffer, char *delim)
{
	char **split_string;
	int i = 0, j, token_num = 0, len;
	char *str = NULL, *token;
	str = strdup(buffer);
	len = strlen(str);
	while (str[i] != '\0')
	{
		if (*(str + i) == ' ')
			token_num++;
		i++;
	}
	token_num++;
	split_string = malloc(sizeof(char) * (len + 1));

	for (j = 0; j < token_num; j++)
	{
		if (j == 0)
		{			
			token = strtok(str, delim);
			split_string[j] = malloc(sizeof(char) * (strlen(token) + 1));
			strcpy(split_string[j], token);
		}
		else
		{
			token = strtok(NULL, delim);
			split_string[j] = malloc(sizeof(char) * (1 + strlen(token)));
			strcpy(split_string[j], token);
		}
	}
	split_string[token_num] = NULL;
	return (split_string);
}
