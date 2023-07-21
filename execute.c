#include "main.h"
/**
 *execute - function to execute the commands
 *@command: the command that should be executed
 */
void execute(char **command)
{
	char *actual_command = command[0];
	char *command_path = NULL;
	pid_t child;
	int status, check_build;

	check_build = built_in_handler(command);
	if (!check_build)
	{
		command_path = _which(actual_command);
		if (command_path)
		{
			actual_command = command_path;
		}
		/* TODO: fork must not be called if the command doesn’t exist */
		child = fork();
		if (child < 0)
		{
			perror("Error:");
			exit(errno);

		}
		else if (child == 0)
		{
			/* TODO: execve will be the core part of your Shell, */
			/* TODO: don’t forget to pass the environ to it… */
			if (execve(actual_command, command, NULL) == -1)
			{
				perror(actual_command);
				exit(errno);
			}
		}
		else
			wait(&status);
	}
	free(command_path);
}
/**
 * built_in_handler - dtermines whether the command is built in or not
 * @builtin: command
 * Return: 0
 */
int built_in_handler(char **builtin)
{
	int builtIntSize= 4;
	char *_env = "env";
	int i;

	built_in check_built[] = {
		{"cd", _cd},
		{"exit", exitt},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv}
	};

	if (_strcmp(builtin[0], _env) == 0)
	{
		_printenv();
		return (1);
	}
	for (i = 0; i < builtIntSize; i++)
	{
		if (_strcmp(check_built[i].name, builtin[0]) == 0)
		{
			check_built[i].func(builtin);
			return (1);
		}
	}
	return (0);
}
