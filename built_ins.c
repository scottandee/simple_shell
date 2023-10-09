#include "shell.h"

/**
  * print_env - this prints out all the environment variables
  * @args: this is the array of split strings passed by the user
  * Return: 0 on success
  */
int print_env(char **args)
{
	int i = 0;
	envi_t *head;
	char *new_line = "\n";
	(void)args;

	head = envi;
	while (head != NULL)
	{
		write(STDOUT_FILENO, head->name, _strlen(head->name));
		write(STDOUT_FILENO, "=", 1);
		write(STDOUT_FILENO, head->value, _strlen(head->value));
		write(STDOUT_FILENO, new_line, 1);
		head = head->next;
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

/**
  * set_environ - Set an environment variable
  *
  * @args: This is the array of split strings passed by the user
  * Return: 0 on success, 1 on error
  */

int set_environ(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		i++;
	}
	if (i != 3)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (1);
	}
	if (_setenv(args[1], args[2]) == -1)
	{
		return (1);
	}
	return (0);
}

/**
  * unset_environ - Unset an environment variable
  *
  * @args: This is the array of split strings passed by the user
  * Return: 0 on success, 1 on error
  */

int unset_environ(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		i++;
	}
	if (i != 2)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (1);
	}
	if (_unsetenv(args[1]) == -1)
	{
		return (1);
	}
	return (0);
}
