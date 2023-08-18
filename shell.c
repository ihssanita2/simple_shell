#include "header.h"
/* Collabration of JalalErr & ihssaneer*/

/* main function :*/
/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: Always returns 0 to indicate successful execution.
 */
int main(__attribute__((unused))int argc, __attribute__((unused))char *argv[])
{
	/*Declaration section :*/
	char *line = NULL;
	size_t line_len = 0;
	ssize_t r_line = 0;
	/*Code section :*/
	if (!(isatty(STDIN_FILENO))) /*non interactive mode*/
	{
		/*_print_string("#cisfun$ "); Print prompt*/
		while ((r_line = getline(&line, &line_len, stdin)) != -1)
		{
			/* 			if (r_line == -1)
						{	if (line)
						free(line);
						break; } */
			if (r_line == 1 && line[0] == '\n')
			{	free(line);
				continue; }
			line[r_line - 1] = '\0'; /* replace the \n*/
			_cmd_execut(line); /*execute the command*/
			free(line);
			line = NULL;
		}
		if (line)
			free(line);
	}
	/* else if ((isatty(STDIN_FILENO)))
	   {
	   line = argv[1];
	   _cmd_execut(line);
	   } */
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
	char **flag = NULL;
	char *const envp[] = {NULL};
	int status;
	/*Code section :*/
	chp_id = fork();
	if (chp_id == 0)
	{
		flag = _cmd_parsing(command, " ");
		if (execve(command, flag, envp) == -1)
		{
			perror(command);
			_free_fun(flag);
		}
		_free_fun(flag);
	}
	else if (chp_id > 0)
	{
		waitpid(chp_id, &status, 0);
		status >>= 8;
	}
}

/* function 2 : _cmd_parsing*/

/**
 * _cmd_parsing - Tokenize a given command using a specified delimiter.
 * @command: The command to be parsed.
 * @delimiter: The character used as a delimiter to split the command.
 * Return: an array of tokens, or NULL on memory allocation failure.
 */
char **_cmd_parsing(char *command, char *delimiter)
{
	/*Declaration section :*/
	char **signif_expres, *tmp = NULL, *cmd_cp = _strdup(command);
	int expres_nbr = 0;
	/*Code section :*/
	tmp = strtok(cmd_cp, delimiter);
	while (tmp != NULL)
	{
		expres_nbr++;
		tmp = strtok(NULL, delimiter);
	}
	free(cmd_cp);
	signif_expres = (char **)malloc(sizeof(char *) * (expres_nbr + 1));
	tmp = strtok(command, delimiter);
	expres_nbr = 0;
	while (tmp != NULL)
	{
		signif_expres[expres_nbr++] = tmp;
		if (signif_expres == NULL)
		{
			perror("Memory allocation error");
			return (0);
		}
		tmp = strtok(NULL, delimiter);
		expres_nbr++;
	}
	signif_expres[expres_nbr] = NULL;
	return (signif_expres);
}
/* function 3 : _free_fun*/

/**
 * _free_fun -
 * @command:
 * Return:
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
