#include "shell.h"

/**
 * my_memset - fills  byte value
 * @s: pointer to the memory area
 * @b: byte memory with
 * @n: number of bytes to be filled
 * _memset - fills memory with a constant byte
 * @s: pointer area
 * @b: *s with
 * @n: the to be filled
 * Return: (s) a pointer to the memory area s
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
 * @ptr: pointer previous allocated block
 * @old_size: size previous block
 * @new_size: size new block
 *
 * Return: pointer
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
