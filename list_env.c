#include "main.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: head to a linked list
 * @str: string element to store
 *
 * str needs to be duplicated
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_env *add_env_end(list_env *head, char *str)
{
	list_env *new_node, *p;
	char **split_array = NULL;

	new_node = malloc(sizeof(list_env));
	if (new_node == NULL)
		return (NULL);

	split_array = split_str(str);
	new_node->name = strdup(split_array[0]);
	new_node->value = strdup(split_array[1]);
	new_node->next_env = NULL;

	if (head == NULL)
	{
		head = new_node;
		free(split_array[0]);
		free(split_array[1]);
		return (head);
	}

	p = head;
	while (p->next_env != NULL)
		p = p->next_env;
	p->next_env = new_node;

	free(split_array[0]);
	free(split_array[1]);
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
		buff[letters] = '\n';
		new_node = add_env_end(env_head,buff);
		if (new_node == NULL)
			free_list_env();
		i++;
	}
	free(buff);
	return (env_head);
}

/**
* free_list - frees a list_path list
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
