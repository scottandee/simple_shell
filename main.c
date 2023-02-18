#include "shell.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *dollar = "$ ";
	size_t size = 0;
	char *buffer = NULL;
	ssize_t read;
	int status = 1;

	while (status)
	{
		write(STDOUT_FILENO, dollar, 2);
		read = getline(&buffer, &size, stdin);
		if (read != -1)
		{
			argv = token_gen(buffer, " \n");
			argv[0] = find_path(argv[0]);
			if (argv[0] == NULL)
				perror("./shell");
			execute(argv);
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

