#include "shell.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *dollar = "$ ";
	size_t size = 0;
	char *buffer = NULL;
	char **args;
	ssize_t read;

	while (1)
	{
		write(STDOUT_FILENO, dollar, 2);
		read = getline(&buffer, &size, stdin);
		if (read != -1)
		{
			args = token_gen(buffer, " \n");
			execute(args);
			free(args);
			free(buffer);
			/*write(STDOUT_FILENO, args[0], sizeof(char) * _strlen(args[0]));
			printf("%s, %lu", args[1], strlen(args[1]));*/
		}
		if (read == -1)
		{
			break;
		}


	}
	return (0);

}

