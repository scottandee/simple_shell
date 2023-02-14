#include "shell.h"

void execute(char **argv)
{
	pid_t mypid;
	int status;
	mypid = fork();
	if (mypid == -1)
	{
		perror("Error");
	}

	if (mypid == 0)
	{
		execve(argv[0], argv, NULL);
	}
	else
	{
		wait(&status);
	}
}
