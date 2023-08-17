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
int _str_len(char *str);
int _str_cmp(char *str1, char *str2);

void _cmd_execut(char *command);
int _lent_string(char *str);
void _exit_cmd(char *command);

#endif /*HEADER_H*/
