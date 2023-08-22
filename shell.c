#include "header.h"
/* Collabration of JalalErr & ihssaneer*/

/* main function :*/
/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: Always returns 0 to indicate successful execution.
 */
int main(__attribute__((unused))int argc, char *argv[])
{
	/*Declaration section :*/
	char *line = NULL;
	size_t line_len = 0;
	ssize_t r_line = 0;
	int count_cmd = 0;
	/*Code section :*/
	if (!(isatty(STDIN_FILENO)))
	{
		non_interactive_shell(argv[0]);
	}
	while (TRUE)
	{
		count_cmd++;
		_print_string("#cisfun$ ");
		r_line = getline(&line, &line_len, stdin);
		if (r_line == -1)
		{
			if (line)
				free(line);
			_putchar('\n');
			exit(0);
		}
		if (r_line == 1 && line[0] == '\n')
		{	free(line);
			continue; }
		line[r_line - 1] = '\0'; /* replace the \n*/
		_cmd_execut(line, argv[0], count_cmd); /*execute the command*/
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	return (0);
}

/* function 1 : _cmd_execut*/

/**
 * _cmd_execut - Execute the given command.
 * @command: The given command to be executed.
 * @argv: the name of the programe.
 * @count: the count of commands.
 * Return: does not return a value directly, it performs
 * the command execution and waits for the child process to complete.
 */
int _cmd_execut(char *command, char *argv, int count)
{
	/*Declaration section :*/
	pid_t chp_id;
	char **flag = NULL;
	char *const envp[] = {NULL};
	int status, i;
	/*Code section :*/
	flag = _cmd_parsing(command, " ");
	if (!flag)
	{
		return (0);
	}
	if (i == _check_cmd(flag, argv, count))
	{
		free(flag);
		return (i);
	}
	chp_id = fork();
	if (chp_id == 0)
	{
		if (execve(flag[0], flag, envp) == -1)
		{
			perror(command);
			free(flag);
		}
	}
	else if (chp_id > 0)
	{
		waitpid(chp_id, &status, 0);
		status >>= 8;
		free(flag);
	}
	return (0);
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
	if (expres_nbr == 0)
		return (NULL);
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
	}
	signif_expres[expres_nbr] = NULL;
	return (signif_expres);
}

/* function 4 : non interactive*/

/**
 * non_interactive_shell - handle the non_interactive_shell.
 * @argv: the commande to execute in the non_interactive_shell.
 * Return: void.
 */
void non_interactive_shell(char *argv)
{
	/*Declaration section :*/
	char *line = NULL;
	size_t line_len = 0;
	ssize_t r_line = 0;
	int count_cmd = 0, exit_code = 0;
	/*Code section :*/
	(void)argv;
	while ((r_line = getline(&line, &line_len, stdin)) != -1)
	{
		count_cmd++;
		if (r_line == 1 && line[0] == '\n')
		{	free(line);
			continue; }
		line[r_line - 1] = '\0'; /* replace the \n*/
		exit_code = _cmd_execut(line, argv, count_cmd); /*execute the command*/
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	exit(exit_code); /*à specifier le code par la suite*/
}
/* function 5 : */

/**
 * _check_cmd - checking if the file exist & if the file is executable.
 * @flag: the programe name.
 * @argv: the command to execute.
 * @count_cmd: the count of commands.
 * Return: 0 on success, code errors if it fails.
 */
int _check_cmd(char **flag, char *argv, int count_cmd)
{
	if (access(flag[0], F_OK) != 0)
	{
		_print_string_err(argv);
		write(2, ": ", 2);
		_putchar_err(count_cmd + '0');
		write(2, ": ", 2);
		_print_string_err(flag[0]);
		_print_string_err(": not found\n");
		return (127);
	}

	if (access(flag[0], X_OK) != 0)
	{
		_print_string_err(argv);
		write(2, ": ", 2);
		_putchar_err(count_cmd + '0');
		write(2, ": ", 2);
		_print_string_err(flag[0]);
		_print_string_err(": permission denied\n");
		return (126);
	}
	return (0);
}
