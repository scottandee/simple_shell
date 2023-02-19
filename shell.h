#ifndef _SHELL_H
#define _SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
int execute(char **args);
int exit_shell(char **args);
int print_env(char **args);
char *_strtok(char *str, const char *delim);
int get_builtin_func(char **args);
char *_strcpy(char *dest, const char *src);
size_t _strlen(const char *s);
char **token_gen(char *buffer, char *delim);
char *_getenv(const char *name);
char *find_path(char *command);

#endif /* _SHELL_H */
