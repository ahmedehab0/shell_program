#include "main.h"

/**
 *_puts - function to print a string to stream
 *@str: string to be printed
 *return: number of chars printed
 */
int _puts(char *str)
{
	int i;
	
	if (!str)
		return (0);

	i = 0;
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
/**
 *_putchar - prints a char to the stream
 *@c: char to be printed
 *return: 1
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
