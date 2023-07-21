#include "main.h"
/**
 * _isatty - determine whether a fd refers to a terminal or not
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("($) ");
}
/**
 * sig_handler - handles the sigint (CTR - c) signal
 * @sig: sigint
 */
void sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		free_list_env();
		_puts("\n($) ");
	}
}
/**
 * main - simple shell program
 * @ac: num of arguments
 * @av: string argument
 * @envp: environment
 * Return: 0
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)),
		 char *envp[] __attribute__((unused)))
{
	ssize_t nread;
	size_t n;
	char **arg, *lineptr;
	char *delim = " \n\t";

	env_head = NULL;
	signal(SIGINT, sig_handler);
	while (1)
	{
		lineptr = NULL;
		_isatty();
		nread = getline(&lineptr, &n, stdin);
		if (nread == EOF)
		{
			free_list_env();
			free(lineptr);
			exit(1);
		}

		arg = string_parse(lineptr, delim);
		if(_strcmp(arg[0], "") == 0)
		{
			free(lineptr);
			free(arg);
			continue;
		}
		execute(arg);
		free(lineptr);
		free(arg);
	}
	return (0);
}
