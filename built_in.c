#include "main.h"

/**
 *_cd - change directory built in command
 *@command: parsed string
 */
void _cd(char **command)
{
	char cwd[256];
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
}

/**
 * _env - print environment
 * @command: unused command line
 */
void _env(__attribute__((unused)) char **command)
{
	_printenv();
}

/**
 * _setenv - see set_env function
 * @command: string pointer
 */
void _setenv(char **command)
{
	int status;

	status = set_env(command[1], command[2], 1);

	if (status == -1)
		perror("failure");
}

/**
 * _unsetenv - see unset_env function
 * @command: string pointer
 */
void _unsetenv(char **command)
{
	int status;

	status = unset_env(command[1]);

	if (status == -1)
		perror("failure");
}

/**
 * _exit_ - exits the shell
 * @command: status of the exit function
 */
void _exit_(char **command)
{
	int i;

	if (exit_status != 127 && exit_status != -1)
		exit_status = 0;

	if (exit_status == -1)
		exit_status = 2;
	
	free_list_env();
	for (i = 0; command[i]; i++)
		;
	if (i == 1)
	{
		free(command[0]);
		free(command);
		exit(exit_status);
	}
	else
	{
		exit_status = _atoi(command[1]);
		if (exit_status < 0)
		{

			exit_status = 2;
			_perror("exit", shell_name, ": Illegal number: ");
			_puts(command[1], STDERR_FILENO);
			_puts("\n", STDERR_FILENO);
		}

		free(command[0]);
		free(command);
		exit(exit_status);
	}
}
