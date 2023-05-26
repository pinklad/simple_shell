#include "shell.h"

/**
 * my_memset - fills memory with a specified byte value
 * @s: pointer to the memory area
 * @b: byte value to fill the memory with
 * @n: number of bytes to be filled
 *
 * Return: a pointer to the memory area s
 */
char *my_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * custom_free - frees a string of strings
 * @pp: string of strings to be freed
 */
void custom_free(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * my_realloc - reallocates a block of memory
 * @ptr: pointer to the previous allocated block
 * @old_size: size of the previous block in bytes
 * @new_size: size of the new block in bytes
 *
 * Return: pointer to the reallocated memory block
 */
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
