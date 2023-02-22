#include "shell.h"
/**
  * main - this is the entry point function
  * @argc: this is the number of arguments passed
  * @argv: this is a string of arguments passed
  * Return: Always 0
  */
int main(int argc, char **argv)
{
	int status = 1, built;

	while (status)
	{
		char *input = read_input();
		argc = 0;
		argv = token_gen(&argc, input, " \n");
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
	return (0);

}

void freeArray(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

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
		return(NULL);
	}
	return (buffer);
}
