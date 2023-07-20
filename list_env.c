#include "main.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @str: string element to store
 *
 * str needs to be duplicated
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_env *add_env_end(char *str)
{
	list_env *new_node, *p;
	char **split_array = NULL, *delim = "=";

	new_node = malloc(sizeof(list_env));
	if (new_node == NULL)
		return (NULL);

	split_array = string_parse(str, delim);
	new_node->name = strdup(split_array[0]);
	new_node->value = strdup(split_array[1]);
	new_node->next_env = NULL;

	free(split_array);
	if (env_head == NULL)
	{
		env_head = new_node;
		return (env_head);
	}
	p = env_head;
	while (p->next_env != NULL)
		p = p->next_env;
	p->next_env = new_node;

<<<<<<< HEAD
=======
	free(split_array);	
>>>>>>> parent of 7de4b9d... free buff
	return (new_node);
}

/**
 * list_environment - make a linked list od environment
 *
 * Return: a list of environment
 */
list_env *list_environment(void)
{
	char *buff;
	int letters;
	int i = 0;
	list_env *new_node;

	while (environ[i])
	{
		letters = _strlen(environ[i]);
		buff = _strdup(environ[i]);
		buff[letters] = '\0';
		new_node = add_env_end(buff);
		if (new_node == NULL)
		{
			free_list_env();
			return (NULL);
		}
		i++;
	}
	free(buff);
	return (env_head);
}

/**
* free_list_env - frees a list_env list
*/
void free_list_env(void)
{
	list_env *current_node;

	if (env_head == NULL)
		return;

	current_node = env_head;
	while (current_node != NULL)
	{
		env_head = env_head->next_env;
		free(current_node->name);
		free(current_node->value);
		free(current_node);
		current_node = env_head;
	}
	free(env_head);
}

/**
 * _printenv - print environment
 * you can list the environment with the command _printenv
 */
void _printenv(void)
{
	char *buff;
	int letters, wr_cmd;
	list_env *p;

	if (env_head == NULL)
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
