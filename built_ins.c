#include "shell.h"

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

/**
  * exit_shell - This exits the shell with a specified parameter
  *
  * @args: This is the array of split strings passed by the user
  * Return: The value of exit status passed
  */
int exit_shell(char **args)
{
	int status;

	if (_strcmp(args[1], "0") == 0)
	{
		return (0);
	}

	status = _atoi(args[1]);
	if (status == 0 || status < 0)
	{
		fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", args[1]);
		return (2);
	}
	else if (status > 255)
	{
		return (status % 256);
	}
	else
	{
		return (status);
	}
	return (-1);
}
