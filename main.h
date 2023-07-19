#ifndef MAIN_H
#define MAIN_H

/*--------- <libraries>------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>

/**
 *struct list_path- linked list containing path directories
 *@dir - name of the directory
 *@next_node - pointer to the node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *next_node;
}list_path;

/**
 *struct built_in - struct to the built in commands and the corresponding function  
 *@name - built in command 
 *@func - corresponding function 
 */
typedef struct built_in
{
	char *name;
	void (*func)(char **);
}built_in;

/* -------------------<functions>--------------------- */

void _isatty();
void sig_handler(int sig);
void execute(char **command);
int _puts(char *str);
int _putchar(char c);
/* -------------------< functions in directories_list.c >--------------------- */

extern char **environ;
list_path *add_node_end(list_path **head, const char *str);
char *_strdup(const char *str);
void free_list(list_path *head);
list_path *list_path_directory(void);

/* -------------------< functions in execute.c >------------------------------- */

int built_in_handeler(char **builtin);
// void _setenv(char **command);
// void _unsetenv(char **command);

/* -------------------< functions in _which.c >------------------------------- */

char *_which(char *file_name);
char *str_concat(char *s1, char *s2);

/* -------------------< functions in list_env.c >------------------------------- */

/**
 * struct list_env - linked list containing environment
 * @name: name of environment
 * @value: value of environment
 * @next_env: pointer to the next node
 */
typedef struct list_env
{
	char *name;
	char *value;
	struct list_env *next_env;
}list_env;

list_env *env_head = NULL;
list_env *add_env_end(list_env *head, char *str);
list_env *list_environment(void);
void free_list_env(void);

/* -------------------< functions in _env.c >------------------------------- */

char *_getenv(const char *var_name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
void _printenv(void);

/* ------------------< functions in string_parse.c >----------------------- */

char **string_parse(char *srr);
void *_realloc(void *ptr, int new_size);
char **split_str(char *str);
int _strlen(const char *s);

/* -----------------< functions in _cd.c>---------------------------------- */

void _cd(char **command);
int _strcmp(const char *s1, const char *s2);

/* ----------------< functions in _exit.c>--------------------------------- */

void exitt(char **command);
int _atoi(char *s);
void free_arg(char **arg);

#endif
