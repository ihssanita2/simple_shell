#include "header.h"

/* Collabration of JalalErr & ihssaneer*/

/* function 1 : _putchar*/

/**
 * _putchar - Write a character to the standard output.
 * @c: The character to be written.
 * Return: 1 on success or -1 on error.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/* function 2 : _print_string*/

/**
 * _print_string - The string to be written.
 * @str: The string to be written.
 * Return: the number of characters written, or -1 on error.
 */
int _print_string(char *str)
{
	int len = 0;

	len = _lent_string(str);
	return (write(STDOUT_FILENO, str, len));
}

/* function 3 : _lent_string*/

/**
 * _lent_string - return the length of a string.
 * @str: the string to mesure.
 * Return: the length of a string.
 */
int _lent_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/* function 4 : _strdup*/

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: The array to duplicate.
 * Return: returns a pointer to the duplicated string
 * and NULL if insufficient memory was available.
 */
char *_strdup(char *str)
{
	unsigned int i, size;
	char *Array;

	if (str == NULL)
	{
		return (NULL);
	}
	size = 1 + _lent_string(str);
	Array = (char *)malloc(size);
	if (Array == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		Array[i] = str[i];
	}
	Array[i] = '\0';
	return (Array);
}
