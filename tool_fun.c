#include "header.h"

/* Collabration of JalalErr & ihssaneer*/

/* function 1 : _putchar*/

/**
 * _putchar - 
 * @c:
 * Return:
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/* function 2 : _print_string*/

/**
 * _print_string - 
 * @str:
 * Return:
 */
int _print_string(char *str)
{
	int len = 0;
	
	len = _lent_string(str);
	return (write(STDOUT_FILENO, str, len));
}

/* function 3 : _lent_string*/

/**
 *	_lent_string - return the length of a string.
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