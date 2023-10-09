#include "shell.h"

/**
  * get_builtin_func - this picks out the right builtin entered by the user
  * @args: This is the input by the user
  * Return: -1 if failure, correct builtin if successful
  */
int get_builtin_func(char **args)
{
	char *builtin_str[] = {
		"env",
		"setenv",
		"unsetenv"
	};
	int (*builtin_func[]) (char **) = {
		&print_env,
		&set_environ,
		&unset_environ
	};
	int i;
	int builtin_num = sizeof(builtin_str) / sizeof(char *);

	for (i = 0; i < builtin_num; i++)
	{
		if (_strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	return (-1);
}


