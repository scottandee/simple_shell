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



		/*built = get_builtin_func(tokens);
		if (built == 0)
		{
			status = 0;
		}
		if (built == -1)
		{
			tokens[0] = find_path(tokens[0]);
			status = execute(tokens);
		}*/
	
