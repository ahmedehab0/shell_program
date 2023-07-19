#include "main.h"
/**
 *_isatty - determine whether a fd refers to a terminal or not
 */
void _isatty()
{
	if (isatty(STDIN_FILENO))
		_puts("($) ");
}
/**
 *sig_handler - handels the sigint (CTR - c) signal
 *@sig - sigint
 */
void sig_handler(int sig)
{
	if (sig == SIGINT)
	_puts("\n($) ");
}
/**
 * main - simple shell program  
 *@ac: num of arguments
 *@av: string argument
 *Return: 0
 */
int main(int ac __attribute__((unused)), char **av, char *envp[] __attribute__((unused)))
{
	ssize_t nread;
	size_t n;
	char **arg, *lineptr = NULL, *shell_name = av[0],
	*delim = " ";
	(void) shell_name;

	signal(SIGINT, sig_handler);
	while (1)
	{
		_isatty();
		nread = getline(&lineptr, &n, stdin);
		if (nread == EOF)
		{
			exit(1);
		}

			arg = string_parse(lineptr, delim);
			execute(arg);
	}
	free(lineptr);
	free_arg(arg);
	return (0);
}
