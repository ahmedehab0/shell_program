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
	_puts("\n($) ");
}
/**
 * main - simple shell program  
 *@ac: num of arguments
 *@av: string argument
 *Return: 0
 */
int main(int ac, char **av)
{
	ssize_t nread;
	size_t n;
	char *lineptr = NULL, **arg;
	(void) ac; (void) av;

	signal(SIGINT, sig_handler);
	while (1)
	{
		_isatty();
		nread = _getline(&lineptr, &n, stdin);
		if (nread == EOF)
			exit(1);

			arg = string_parse(lineptr);
			execute(arg);
	}
	free(lineptr);
	free(arg);
	return (0);
}
