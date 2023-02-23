#include "shell.h"
/**
  * main - this is the entry point function
  * @argc: this is the number of arguments passed
  * @argv: this is a string of arguments passed
  * Return: Always 0
  */
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	hsh_loop();

	return (0);
}


int hsh_loop(void)
{
	char *buffer = NULL;
	int status = 1;/*, built*/
	size_t size = 0;
	char *dollar = "$ ";
	while (status)
	{
		int i = 1;
		ssize_t parsed = 0;
		char *delim = " ";
		char **tokens = malloc(1024 * sizeof(char *));
		if (tokens == NULL)
		{
			free(tokens);
			return (0);
		}
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, dollar, 2);
		}
		parsed = getline(&buffer, &size, stdin);
		if (parsed == -1)
		{
			free(buffer);
			free(tokens);
			return (-1);
		}
		*(buffer + (_strlen(buffer) - 1)) = '\0';
		tokens[0] = strtok(buffer, delim);
		tokens[1] = "gb";
		while (tokens[i])
		{
			tokens[i] = strtok(NULL, delim);
			i++;
		}
		tokens[i] = NULL;
		status = execute(tokens);
		free(tokens);
		/*built = get_builtin_func(argv);
		if (built == 0)
		{
			status = 0;
		}
		if (built == -1)
		{
			argv[0] = find_path(argv[0]);
			execute(argv);
		}*/
	}
	return (0);
}
