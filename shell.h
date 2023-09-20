#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *s);
char *_strtok(char *str, const char *delim);

char *read_input(void);
void free_tokens(char **tokens, int argc);
char **split_input(char *input_text, int *argc);
int execute(char **args);
char *_getenv(char *name);
int get_builtin_func(char **args);
char *find_path(char *command);

extern char **environ;

int exit_shell(char **args);
int print_env(char **args);

#endif /*_SHELL_H_*/
