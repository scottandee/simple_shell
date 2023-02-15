#ifndef _SHELL_H
#define _SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int execute(char **args);
char *_strtok(char *str, const char *delim);
char *_strcpy(char *dest, const char *src);
size_t _strlen(const char *s);
char **token_gen(char *buffer, char *delim);

#endif /* _SHELL_H */
