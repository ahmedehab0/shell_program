#include "main.h"
/**
 *_cd - change directory built in command
 *@command: parsed string 
 */
void _cd(char **command)
{
	char *cwd;
	int value;

	if (!command[1])
		value = chdir(_getenv("HOME"));

	else if (!_strcmp("-", command[1]))
	{
		value = chdir(_getenv("OLDPWD"));
		if (value == -1)
		{
			perror("OLDPWD");
			return;
		}
	}
	else
		value = chdir(command[1]);

	if (value == -1)
	{
		perror("PWD");
		return;
	}
	getcwd(cwd, sizeof(cwd));
	set_env("OLDPWD", _getenv("PWD"), 1);
	set_env("PWD", cwd, 1);

	free(cwd);
}
/**
 *_strcmp - function to compare to strings
 *@s1: first string to be compared
 *@s2: second string to be compared
 *Return: 0 on success
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (1);
	}
	return (0);

}
