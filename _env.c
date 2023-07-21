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
	list_env *p;

	if (env_head == NULL)
		env_head = list_environment();
	if (env_head == NULL)
		return (NULL);

	p = env_head;
	while (p)
	{
		if (_strcmp(p->name, var_name) == 0)
			return (p->value);
		p = p->next_env;
	}
	return (NULL);
}

/**
 * set_env - changes or adds an environment variable
 * @name: name of environment
 * @value: value of environment
 * @overwrite: new value of environment
 *
 * If name does not exist in the environment:
 * adds the variable name to the environment with the value.
 *
 * If name does exist in the environment:
 * then its value is changed to value if overwrite is nonzero;
 * if overwrite is zero, then the value of name is not changed
 * (and setenv() returns a success status)
 *
 * Return: return zero on success, or -1 on error,
 * with errno set to indicate the error.
 */
int set_env(const char *name, const char *value, int overwrite)
{
	list_env *p;

	if (env_head == NULL)
		env_head = list_environment();
	if (env_head == NULL)
		return (-1);

	p = env_head;
	while (p)
	{
		if (_strcmp(p->name, name) == 0)
		{
			if (overwrite != 0)
				p->value = strdup(value);
			return (0);
		}
		p = p->next_env;
	}
	p = malloc(sizeof(list_env));
	if (p == NULL)
		return (-1);

	p->name = _strdup(name);
	p->value = _strdup(value);
	p->next_env = NULL;
	return (0);
}

/**
 * unset_env - deletes the variable name from the environment
 * @name: name of environment
 *
 * If name does not exist in the environment, then the function succeeds,
 * and the environment is unchanged.
 *
 * Return: return zero on success, or -1 on error,
 * with errno set to indicate the error.
 */
int unset_env(const char *name)
{
	list_env *prev, *current;

	if (env_head == NULL)
		env_head = list_environment();
	if (env_head == NULL)
		return (-1);

	prev = NULL;
	current = env_head;

	while (current)
	{
		if (_strcmp(current->name, name) == 0)
		{
			prev->next_env = current->next_env;
			free(current->name);
			free(current->value);
			free(current);
			return (0);
		}
		prev = current;
		current = current->next_env;
	}
	/* when to return (-1) ? */
	return (0);
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
