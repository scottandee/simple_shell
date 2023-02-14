#include "shell.h"

int main(int argc, char **argv)
{
	(void)argc;
	char *dollar = "$ ";
	size_t size = 0;
	char *buffer = NULL;
	ssize_t read;

	while (1)
	{
		write(STDOUT_FILENO, dollar, 2);
		read = getline(&buffer, &size, stdin);
		if (read != -1)
		{
			argv = token_gen(buffer, " ");
			execute(argv);
			buffer = NULL;
		}
		else
		{
			break;
		}


	}
	return (0);

}

