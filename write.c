#include "main.h"

/**
 * _puts - function to print a string to stream
 * @str: string to be printed
 * Return: number of chars printed
 */
int _puts(char *str, int stream)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		write(stream, &str[i], 1);
	}
	return ((i + 1));
}

/**
 * _isatty - determine whether a fd refers to a terminal or not
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("($) ", 1);
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
		_puts("\n($) ", 1);
	}
}
