#include "shell.h"

int execute(char **args)
{
	pid_t mypid;
	int status, exe;

	mypid = fork();
	if (mypid == -1)
	{
		perror("Error");
	}

	if (mypid == 0)
	{
		exe = execve(args[0], args, NULL);
		if (exe == -1)
		{
			perror("Error");
		}
	}
	else
	{
		wait(&status);
	}
	return (1);
}
