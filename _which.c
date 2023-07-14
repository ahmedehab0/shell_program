#include "main.h"

/**
 * _which - looks for files in the current PATH.
 * @file_name: file name
 *
 * Return: file path
 */
char *_which(char *file_name)
{
	char cwd[256];
	char *dir_path;
	char *c_w_d;
	char *c_w_d_temp;
	list_path *path_directories, *head;
	struct stat st;
	int i = 0;

	path_directories = list_path_directory();
	head = path_directories;
	getcwd(cwd, sizeof(cwd));

	if (stat(file_name, &st) == 0)
	{
		free_list(head);
		return (file_name);
	}

	while (path_directories != NULL)
	{
		dir_path = path_directories[i].dir;
		chdir(dir_path);
		if (stat(file_name, &st) == 0)
		{
			c_w_d_temp = dir_path;
			c_w_d = str_concat(c_w_d_temp, "/");
			c_w_d_temp = str_concat(c_w_d, file_name);
			free(c_w_d);
			chdir(cwd);
			free_list(head);
			return (c_w_d_temp);
		}
		path_directories = path_directories->next_node;
	}
	chdir(cwd);
	free_list(head);
	return (NULL);
}

/**
 * str_concat - concatenates two strings.
 * @s1: First string
 * @s2: Second string
 *
 * The returned pointer should point to a newly allocated space
 * in memory which contains the contents of s1,
 * followed by the contents of s2, and null terminated
 * if NULL is passed, treat it as an empty string
 *
 * Return: A pointer to concatenated string or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *str_concat;
	int s1_size;
	int s2_size;
	int i, j;

	if (s1 == NULL)
	{
		s1_size = 0;
	}
	else
	{
		for (s1_size = 0; s1[s1_size]; s1_size++)
			;
	}
	if (s2 == NULL)
	{
		s2_size = 0;
	}
	else
	{
		for (s2_size = 0; s2[s2_size]; s2_size++)
			;
	}

	str_concat = malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (str_concat == NULL)
		return (NULL);

	for (i = 0; i < s1_size; i++)
		str_concat[i] = s1[i];

	for (j = 0; j < s2_size; j++, i++)
		str_concat[i] = s2[j];

	str_concat[i] = '\0';

	return (str_concat);
}
