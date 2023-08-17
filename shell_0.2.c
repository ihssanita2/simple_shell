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
	/*Declaration section :*/
	pid_t chp_id;
	char *path = {NULL};
	char *flag[32];
	char *const envp[] = {NULL};
	int status;
	/*Code section :*/
	chp_id = fork();
	if (chp_id == 0)
	{
		flag = _cmd_parsing(command, " ");
		path = flag[0];
		if (execve(path, flag, envp) == 0)
		{
			free(command);
			free(flag);
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
/* function 2 : _cmd_parsing*/

/**
 * _cmd_parsing - Tokenize a given command using a specified delimiter.
 * @command: The command to be parsed.
 * @delimiter: The character used as a delimiter to split the command.
 * Return: an array of tokens, or NULL on memory allocation failure.
 */
char *_cmd_parsing(char *command, char *delimiter)
{
	/*Declaration section :*/
	char *signif_expres, *tmp = NULL;
	int expres_nbr = 0;
	/*Code section :*/
	tmp = strtok(command, delimiter);
	while (tmp != NULL)
	{
		signif_expres[expres_nbr++] = _strdup(tmp);
			if (signif_expres == NULL)
			{
				perror("Memory allocation error");
				return (0);
			}
		tmp = strtok(NULL, delimiter);
		expres_nbr++;
	}
	signif_expres[expres_nbr] = tmp;
	return (signif_expres);
}
