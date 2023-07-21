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
