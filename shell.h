#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**
  * struct envi_s - Datatype for the shell's enviroment variable
  * @name: Name of the variable
  * @value: Value of the variable
  * @next: Pointer to the next variable
  */
typedef struct envi_s
{
	char *name;
	char *value;
	struct envi_s *next;
} envi_t;

int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *s);
char *_strtok(char *str, const char *delim);
int _atoi(char *s);

char *read_input(void);
void free_tokens(char **tokens, int argc);
char **split_input(char *input_text, int *argc);
int execute(char **args);
char *_getenv(char *name);
int _setenv(char *name, char *value);
int _unsetenv(char *name);
int get_builtin_func(char **args);
char **commands(char *input_text);
char *find_path(char *command);

envi_t *add_env_end(envi_t **head, char *name, char *value);
int remove_env_list(char *name);
void free_env_list(void);
envi_t *build_env_list(void);

extern char **environ;
extern int last_command_exit_status;
extern envi_t *envi;

int set_environ(char **args);
int unset_environ(char **args);
int exit_shell(char **args);
int print_env(char **args);
int change_dir(char **args);

#endif /*_SHELL_H_*/
