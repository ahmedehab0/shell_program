#include "main.h"

/**
 *_perror - handels the error massage if the command is not found
 *@command: name of the command
 *@shell_name: name of the program
 *
 */
void _perror(char *command, char *shell_name)
{
	_puts(shell_name, 1);
	_puts(": 1: ", 1);
	_puts(command, 1);
       _puts(": not found", 1);
}
