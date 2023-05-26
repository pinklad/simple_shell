#include "shell.h"

/**
 * free_nullify - frees a pointer and sets the address to NULL
 * @ptr: address of the pointer to be freed
 *
 * Return: 1 if freed successfully, 0 otherwise
 */
int free_nullify(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
