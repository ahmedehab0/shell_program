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

	if(env_head == NULL)
		env_head = list_environment();

	p = env_head;
	while (p)
	{
		/* p->name == var_name) */
		if (*(p->name) == *var_name)
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

	if(env_head == NULL)
		env_head = list_environment();

	p = env_head;
	while (p)
	{
		if (p->name == name)
		{
			if (*value != 0)
				p->value = (char *) overwrite;
			return (0);
		}
		p = p->next_env;
	}
	p = malloc(sizeof(list_env));
	if (p == NULL)
		return (-1);

	p->name = strdup(name);
	p->value = strdup(value);
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

	if(env_head == NULL)
		env_head = list_environment();

	prev = NULL;
	current = env_head;

	while (current)
	{
		if (current->name == name)
		{
			prev->next_env = current->next_env;
			return (0);
		}
		prev = current;
		current = current->next_env;
	}
	/* when to return (-1) ? */
	return (0);
}

/**
 * print_env - print env
 * you can list the environment with the command _printenv
 */
void _printenv(void)
{
	char *buff;
	int letters, wr_cmd;
	list_env *p;

	if(env_head == NULL)
		env_head = list_environment();

	p = env_head;
	while (p)
	{
		buff = _strdup(p->name);
		buff = str_concat(buff, "=");
		buff = str_concat(buff, p->value);
		letters = _strlen(buff);
		wr_cmd = write(STDOUT_FILENO, buff, letters);

		if (wr_cmd == -1)
			perror("Error");
		free(buff);
		p = p->next_env;
	}
}
