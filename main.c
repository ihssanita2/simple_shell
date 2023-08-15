#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void env_builtin(char *const envp[]) {
    for (int i = 0; envp[i] != NULL; i++) {
        printf("%s\n", envp[i]);
    }
}

int main()
{
    char prompt[] = "$ ";
    ssize_t w_return;
    int r_line;
    char *line = NULL;
    size_t lenght = 0;
    char *arg[] = {NULL, NULL};
    char *const envp[] = {NULL};
    pid_t pid;
    char Exit[4] = "exit";
    char *flags[64];
    const char delimiter[] = " ";
    char *token;
    int i = 0;
    char *command = "env";

    while(1)
    {
        w_return = write(STDOUT_FILENO, prompt, 2);
        r_line = getline(&line, &lenght, stdin);
        if (r_line < 0)
            free(line);
        line [r_line  - 1] = '\0';
        arg[0] = line;
        token = strtok(line, delimiter);

        while (token)
        {
            flags[i] = token;
            ++i;
            token = strtok(NULL, delimiter);
        }
        flags[i] = NULL;
        if (strcmp(arg[0], "exit") == 0)
        {
            printf("out of programme\n");
            free(line);
            exit(0);
        }
        if (strcmp(line, command) == 0) 
        {
            // Appeler la fonction pour afficher l'environnement
            env_builtin(environ);
        }

        pid = fork();
        if (pid == 0)
        {
            if (execve(line , arg, envp) == 0)
            {
                free(line);
            }
            else
            {
                perror("Commande not found");
            }
        }
        else if (pid > 0)
        {
            wait(NULL);
        }
        else 
        {
            perror("Error child file executing");
            free(line);
        }
    }
    free(line);

    return 0;
}
