#include "main.h"

/**
 * main - simple shell program
 * @ac: num of arguments
 * @av: string argument
 * @envp: environment
 *
 * Return: 0
 */
int main(int ac __attribute__((unused)), char **av,
		 char *envp[])
{
	char **arg, *line_ptr;
	char *shell_name = av[0];
	char *delim = " \n\t";
	ssize_t char_read;
	size_t n = 0;

	env_head = NULL;
	signal(SIGINT, sig_handler);

	while (1)
	{
		line_ptr = NULL;
		_isatty();
		char_read = getline(&line_ptr, &n, stdin);
		if (char_read == EOF)
		{
			free_list_env();
			free(line_ptr);
			exit(exit_status);
		}

		arg = string_parse(line_ptr, delim, 0);
		if (_strcmp(arg[0], "") == 0)
		{
			free(line_ptr);
			free(arg);
			continue;
		}
		execute(arg, shell_name, envp);
		free(line_ptr);
		free(arg);
	}
	return (0);
}
