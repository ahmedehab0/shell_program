#include "main.h"

/**
 * _getenv - search for the environment string (filename)
 * @var_name: The name of the requested variable
 *
 * var_name = var_value
 * Return: the value of the var_name.
 */
char *_getenv(const char *var_name)
{
	int i, j;
	int is_equal;

	for (i = 0; environ[i] != NULL; i++)
	{
		is_equal = 1;

		for (j = 0; environ[i][j] != '='; j++)
		{
			if (var_name[j] != environ[i][j])
			{
				is_equal = 0;
				break;
			}
		}
		if (is_equal)
			return (&environ[i][j + 1]);
	}
	return (NULL);
}

/**
 * print_env - print env
 * you can list the environment with the command _printenv
 */
void _printenv(void)
{
	char *buff;
	int letters, wr_cmd;
	int i = 0;

	while (environ[i])
	{
		letters = _strlen(environ[i]);
		buff = _strdup(environ[i]);
		buff[letters] = '\n';
		wr_cmd = write(STDOUT_FILENO, buff, (letters + 1));
		free(buff);

		if (wr_cmd == -1)
			perror("Error");
		i++;
	}
}

/**
 * _strlen - get length of string
 * @s: A pointer to char
 *
 * computes the length of the string s up to,
 * but not including the terminating null character.
 *
 * Return: length of string
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len]; len++)
		;

	return (len);
}
