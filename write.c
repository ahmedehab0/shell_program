#include "main.h"

/**
 * _puts - function to print a string to stream
 * @str: string to be printed
 * @stream: file stream
 *
 * Return: number of chars printed
 */
int _puts(char *str, int stream)
{
	int i;

	for (i = 0; str[i]; i++)
		write(stream, &str[i], 1);

	return ((i + 1));
}

/**
 * _perror - handles the error massage if the command is not found
 * @command: name of the command
 * @shell_name: name of the program
 */
void _perror(char *command, char *shell_name)
{
	_puts(shell_name, STDERR_FILENO);
	_puts(": 1: ", STDERR_FILENO);
	_puts(command, STDERR_FILENO);
	_puts(": not found\n", STDERR_FILENO);
}

/**
 * _isatty - determine whether a fd refers to a terminal or not
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("($) ", STDOUT_FILENO);
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
		_puts("\n($) ", STDOUT_FILENO);
	}
}
