#include "header.h"

/* Collabration of JalalErr & ihssaneer*/

/* function 1 : _exit_cmd */

/**
 * _exit_cmd - get out of programme. 
 * @s1: first string.
 * @s2: second string.
 * Return: 0 if s1 and s2 are equals,
 * another number if not.
 */

    int  _exit_cmd(char *s1, char *s2)
    {
        int i = 0, v = 0;

        while (v == 0)
        {
            if ((*(s1 + i) == '\0') && (*(s2 + i) == '\0'))
                break;
            v = *(s1 + i) - *(s2 + i);
            i++;
        }
        return (v);
    }
    