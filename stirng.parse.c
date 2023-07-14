#include "main.h"

/**
 *string_parse - function to tokinize the string
 *@str: string to be tokinized
 *return - array of strings
 */
char **string_parse(char *str)
{
	char **token, *delim = " ";
	int i = 0, buf_size = 1024;

	token = malloc(sizeof(char *) * buf_size);
	if (!token)
	{
		free(token);
		return (NULL);
	}

	token[i] = strtok(str, delim);
	i++;

	while(token[i])
	{
		token[i] = strtok(NULL, delim);
		if (i >= buf_size)
		{
			buf_size += buf_size;
			token = _realloc(token, sizeof (char *) * buf_size);
			if (!token)
			{
				perror("Error");
			}
		}
		i++;
	}
return (token);
}
/**
 *_realloc - function to dinamclly reallocate the memory
 *@new_size: new_size to be reallocated
 *return: pointer to the new memory
 */
void *_realloc(void *ptr, int new_size)
{
	char *new;
	int i;

	if (!ptr)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new = malloc(new_size);
	if (!new)
	{
		free(new);
		return(NULL);
	}
	for (i = 0; new[i]; i++)
	{
		new[i] = ((char *)ptr)[i];
	}
	/*not sure if i should free ptr*/
	free (ptr);

	return (new);
}
