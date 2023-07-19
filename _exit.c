#include "main.h"
/**
 *exitt - exits the shell
 *@command: status of the exit function
 */
void exitt(char **command)
{

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
