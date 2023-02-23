#include "shell.h"
/**
  * execute - this runs the command passed into it
  * @args: this is an array of strings through which the command is passed
  * Return: 1 on success
  * prints out error to stderr if there's failure at any point
  */
int execute(char **args)
{
	pid_t mypid;
	int status, exe;

	if (args[0] == NULL)
	{
		return (1);
	}

	mypid = fork();
	if (mypid == -1)
	{
		perror("./hsh");
	}

	if (mypid == 0)
	{
		exe = execve(args[0], args, NULL);
		if (exe == -1)
		{
			perror("./hsh");
		}
	}
	else
	{
		wait(&status);
	}
	return (1);
}
