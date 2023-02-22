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
char *read_input();
int exit_shell(char **args);
char *removeLeading(char *str);
char *removeLagging(char *str);
void trimleadingandTrailing(char *s);
int print_env(char **args);
char *_strtok(char *str, const char *delim);
char *_strcat(char *dest, const char *src);
int get_builtin_func(char **args);
void freeArray(char **arr);
char *_strcpy(char *dest, const char *src);
size_t _strlen(const char *s);
char **token_gen(char *buffer, char *delim);
char *_getenv(const char *name);
char *_strdup(const char *s);
char *find_path(char *command);
int _strcmp(char *s1, char *s2);

#endif /* _SHELL_H */
