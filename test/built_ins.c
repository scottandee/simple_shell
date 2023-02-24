#include "shell.h"

/**
  * exit_shell - print_env
  * @args: this is the array of split strings passed by the user
  * Return: 0 on succcess
  */

int exit_shell(char **args)
{
	(void)args;
	return (0);
}
/**
  * print_env - this prints out all the environment variables
  * @args: this is the array of split strings passed by the user
  * Return: 0 on success
  */
int print_env(char **args)
{
	int i = 0;
	char *new_line = "\n";
	(void)args;

	while (*(environ + i) != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, new_line, 1);
		i++;
	}
	return (1);
}
