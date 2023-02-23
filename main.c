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

	(void)argc;
	while (status)
	{
		char *input = read_input();

		argv = token_gen(input, " \n");

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
		free(input);
		free(argv);
	}
	/*freeArray(argv);*/
	return (0);
}

