#include "shell.h"

int last_command_exit_status = 0;
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
	char *command;

	if (args[0] == NULL)
	{
		return (0);
	}

	mypid = fork();
	if (mypid == -1)
	{
		perror(args[0]);
		return (1);
	}

	if (mypid == 0)
	{
		command = find_path(args[0]);
		exe = execve(command, args, environ);
		if (exe == -1)
		{
			perror(args[0]);
			exit(2);
		}
	}
	else
	{
		wait(&status);
		last_command_exit_status = WEXITSTATUS(status);
	}
	return (last_command_exit_status);
}
