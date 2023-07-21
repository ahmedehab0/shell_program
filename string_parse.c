#include "main.h"

/**
 * string_parse - function to tokenize the string
 * @str: string to be tokenized
 * @delim: delimiter
 *
 * Return: array of strings
 */
char **string_parse(char *str, char *delim)
{
	char **token;
	int i = 0, buf_size = 1024;

	token = malloc(sizeof(char *) * buf_size);
	if (!token)
	{
		return (NULL);
	}

	token[i] = strtok(str, delim);

	while (token[i])
	{
		token[++i] = strtok(NULL, delim);
		if (i >= buf_size)
		{
			buf_size += buf_size;
			token = _realloc(token, sizeof(char *) * buf_size);
			if (!token)
			{
				perror("Error");
			}
		}
	}
	return (token);
}
/**
 * _realloc - function to dynamically reallocate the memory
 * @ptr: a pointer
 * @new_size: new_size to be reallocated
 *
 * Return: pointer to the new memory
 */
void *_realloc(void *ptr, int new_size)
{
	char *new;
	int i;

	if (!ptr)
	{
		ptr = malloc(new_size);
		if (!ptr)
			return (NULL);
		return (ptr);
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	if (!new)
		return (NULL);

	for (i = 0; new[i]; i++)
		new[i] = ((char *)ptr)[i];

	free(ptr);
	return (new);
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
