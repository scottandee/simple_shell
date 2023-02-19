#include "shell.h"
/**
  * main - this is the entry point function
  * @argc: this is the number of arguments passed
  * @argv: this is a string of arguments passed
  * Return: Always 0
  */
int main(int argc, char **argv)
{
	size_t size = 0;
	char *buffer = NULL;
	ssize_t read;
	int status = 1, built;
	char *dollar;

	dollar = "$ ";
	(void)argc;
	(void)argv;

	while (status)
	{
		write(STDOUT_FILENO, dollar, 2);
		read = getline(&buffer, &size, stdin);
		if (read != -1)
		{
			argv = token_gen(buffer, " \n");
			built = get_builtin_func(argv);
			if (built == 0)
			{
				status = 0;
			}
			if (built == -1)
			{
				argv[0] = find_path(argv[0]);
				execute(argv);
			}
		}
		if (read == -1)
		{
			break;
		}


	}
	free(argv);
	free(buffer);
	return (0);

}

