#include "header.h"

/* Collabration of JalalErr & ihssaneer*/

/* function 1 : _cmd_execut*/

/**
 * _cmd_execut - execute the given command. 
 * @command: the given command.
 * @program_name: the name of the program.
 * Return: void.
 */
void _cmd_execut(char *command)
{
	pid_t chp_id;
	char *const flag[] = {NULL, NULL};
	char *const envp[] = {NULL};
    int status;

    chp_id = fork();
	if (chp_id == 0)
    {
            if (execve(command, flag, envp) == 0)
            {
                free(command);
                exit(0);
            }
            else
            {
                perror(command);
            }
    }
	else if (chp_id > 0)
	{
            waitpid(chp_id, &status, 0);
            status >>= 8;
    }
    else 
	{
            free(command);
	}
}