#ifndef HEADER_H
#define HEADER_H

#define TRUE 1
#define MAX_BUFF 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

/* Print functions :*/
int _putchar(char c);
int _print_string(char *str);

/* Tools functions :*/
int _lent_string(char *str);
char *_strdup(char *str);

/* Annexe functions :*/
void _cmd_execut(char *command);
char *_cmd_parsing(char *command, char *delimiter);
int _str_cmp(char *s1, char *s2);

#endif /*HEADER_H*/
