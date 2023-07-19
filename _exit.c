#include "main.h"
/**
 *exitt - exits the shell
 *@command: status of the exit function
 */
void exitt(char **command)
{
	int status = 0, i;
	char *error_massage = "$: exit doesn't take more than one argument\n";

	for(i = 0; command[i]; i++)
		;
	if (i == 1)
	{
		free_arg(command);
		exit(status);
	}
	else if (i == 2)
	{
		status = _atoi(command[1]);
		if (status <= -1)
			status = 2;

		free_arg(command);
		exit(status);
	}
	else
	{
		write(2, error_massage, _strlen(error_massage));
	}
}
/**
 *_atoi - converts a string to an integer
 *
 *@s: string to be converted
 *return: integer
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
/**
 *free_arg - frees a double a pointer
 *@arg - array of strings
 */
void free_arg(char **arg)
{
	int i;

	for (i = 0; arg[i]; i++)
		free(arg[i]);

	free(arg);
}
