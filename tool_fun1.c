#include "header.h"

/* function 1 : _putchar_err */

/**
 * _putchar_err - Write a character to the standard output.
 * @c: The character to be written.
 * Return: 1 on success or -1 on error.
 */
int _putchar_err(char c)
{
	return (write(2, &c, 1));
}

/* function 2 : _print_string_err*/

/**
 * _print_string_err - The string to be written.
 * @str: The string to be written.
 * Return: the number of characters written, or -1 on error.
 */
int _print_string_err(char *str)
{
	int len = 0;

	len = _lent_string(str);
	return (write(STDERR_FILENO, str, len));
}

/* function 3 : _free_fun*/

/**
 * _free_fun - frees the allocated memory.
 * @Dpointer: the pointer to the memory to free.
 * Return: void.
 */
void _free_fun(char **Dpointer)
{
	int i;

	for (i = 0; Dpointer[i]; i++)
	{
		free(Dpointer[i]);
	}
	free(Dpointer);
}

