#include "shell.h"

/**
 *  - frees a pointer
 * @ptr: address
 *
 * Return: 1 if freed, void
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
