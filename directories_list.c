#include "main.h"


/**
 * list_path_directory - creates a linked list of PATH
 *
 * Return: a linked list of PATH
 */
list_path *list_path_directory(void)
{
	char *path_line = _getenv("PATH");
	char *path_without_delim = NULL;
	char *cpy_path_line = NULL;
	char *delim = ": ";
	list_path *head = NULL;
	list_path *new_node = NULL;

	cpy_path_line = _strdup(path_line);
	path_without_delim = strtok(cpy_path_line, delim);
	while (path_without_delim != NULL)
	{

// not sure if it is new_node or head.
		new_node = add_node_end(&head, path_without_delim);
		if (new_node == NULL)
		{
			free(cpy_path_line);
			free_list(head);
			return (NULL);
		}
		path_without_delim = strtok(NULL, delim);
	}
	free(cpy_path_line);

// not sure if it is correct here!
	free(path_without_delim);
	return (head);
}

/**
 * _getenv - search for the environment string (filename)
 * @var_name: The name of the requested variable
 *
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
		if (is_equal == 1)
			return (&environ[i][j + 1]);
	}
	return (NULL);
}

/**
 * add_node_end - adds a new node at the end of a list_path list
 * @head: head to a linked list
 * @str: string element to store
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_path *add_node_end(list_path **head, const char *str)
{
	list_path *new_node;
	list_path *current_node;

	new_node = malloc(sizeof(list_path));
	if (new_node == NULL)
		return (NULL);

	new_node->dir = _strdup(str);
	new_node->next_node = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}

	current_node = *head;
	while (current_node->next_node != NULL)
		current_node = current_node->next_node;
	current_node->next_node = new_node;

	return (new_node);
}

/**
 * _strdup - duple the string
 * @str: String
 *
 * A function that returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * Returns NULL if str = NULL.
 *
 * Return: A pointer to the duplicated string,
 * or NULL if insufficient memory was available.
 */
char *_strdup(const char *str)
{
	char *str_dup;
	int i, size;

	if (str == NULL)
		return (NULL);

	for (size = 0; str[size]; size++)
		;
	size++;

	str_dup = malloc(sizeof(char) * size);
	if (str_dup == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		str_dup[i] = str[i];
	str_dup[i] = '\0';

	return (str_dup);
}

/**
 * free_list - frees a list_path list
 * @head: head to a linked list
 *
 * a function that frees a list_path list.
 */
void free_list(list_path *head)
{
	list_path *current_node;

	while (head != NULL)
	{
		current_node = head;
		head = head->next_node;
		free(current_node->dir);
		free(current_node);
	}
}

