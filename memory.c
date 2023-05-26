#include "shell.h"

/**
<<<<<<< HEAD
 * free_nullify - frees a pointer and sets the address to NULL
 * @ptr: address of the pointer to be freed
 *
 * Return: 1 if freed successfully, 0 otherwise
=======
 * bfree - address
 * @ptr:  frees the address to pointer
 *
 * Return: 1 if freed, otherwise 0.
>>>>>>> 44bc5d40d7a00415990f432dec4c6573e1a7a153
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
