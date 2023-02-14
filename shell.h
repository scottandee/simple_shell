#ifndef _SHELL_H
#define _SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute(char **argv);
char **token_gen(char *buffer, char *delim);

#endif /* _SHELL_H */
