#include "header.h"
/* Collabration of JalalErr & ihssaneer*/

/* main function :*/
/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: Always returns 0 to indicate successful execution.
 */
int main(int argc, __attribute__((unused)) char *argv[])
{
	/*Declaration section :*/
	char *line = NULL;
	size_t line_len = 0;
	ssize_t r_line = 0;
	/*Code section :*/
	if (argc == 1)
	{
		while (TRUE)
		{
			if (isatty(STDIN_FILENO) == 1)
				_print_string("#cisfun$ "); /*Print prompt*/
			r_line = getline(&line, &line_len, stdin);
			if (r_line == -1)
			{
				free(line);
				break;
			}
			if (r_line == 1 && line[0] == '\n')
				continue;
			line[r_line - 1] = '\0'; /* replace the \n*/
			_cmd_execut(line); /*execute the command*/
			line = NULL;
		}
	}
	else if (argc > 1)
	{
		line = argv[1];
		_cmd_execut(line);
	}
	return (0);
}

/* function 1 : _cmd_execut*/

/**
 * _cmd_execut - Execute the given command.
 * @command: The given command to be executed.
 * Return: does not return a value directly, it performs
 * the command execution and waits for the child process to complete.
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

