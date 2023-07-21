#include "main.h"
/**
 * main - simple shell program
 * @ac: num of arguments
 * @av: string argument
 * @envp: environment
 * Return: 0
 */
int main(int ac __attribute__((unused)), char **av,
		 char *envp[] __attribute__((unused)))
{
	ssize_t nread;
	size_t n;
	char **arg, *lineptr, *shell_name = av[0];
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
		if (_strcmp(arg[0], "") == 0)
		{
			free(lineptr);
			free(arg);
			continue;
		}
		execute(arg, shell_name);
		free(lineptr);
		free(arg);
	}
	return (0);
}
