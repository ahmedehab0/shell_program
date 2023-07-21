#include "main.h"
/**
 * exitt - exits the shell
 * @command: status of the exit function
 */
void exitt(char **command)
{
	int status = 0, i;

	free_list_env();
	for (i = 0; command[i]; i++)
		;
	if (i == 1)
	{
		free(command[0]);
		free(command);
		exit(status);
	}
	else
	{
		status = _atoi(command[1]);
		if (status <= -1)
			status = 2;

                free(command[0]);
		free(command);
		exit(status);
	}
}
/**
 * _atoi - converts a string to an integer
 *
 * @s: string to be converted
 * Return: integer
 */
int _atoi(char *s)
{
	int i, sign = 1, result = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
		}
	}
	return (sign * result);
}
