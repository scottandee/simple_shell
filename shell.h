#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


size_t _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, const char *delim);


int hsh_loop(void);
int execute(char **args);
char **token_gen(char *buffer, char *delim);

extern char **environ;

#endif /*_SHELL_H_*/
