/*
** EPITECH PROJECT, 2019
** ACCES_TO_EXEC
** File description:
** acces and exec function
*/

#include "42sh.h"

int cmd_to_path(stct_42sh_t *mysh)
{
    int   acces        = -1;
    char  buffer[1000] = {0};
    char *tmp          = getcwd(buffer, 1000);

    if (mysh->path[0] == NULL)
        return acces;
    for (int i = 0; mysh->path[i]; i++) {
        mysh->conc = my_strcat(my_strcat(mysh->path[i], "/"), mysh->args[0]);
        if ((access(mysh->conc, X_OK)) == 0) {
            acces = 0;
            break;
        } free(mysh->conc);
    }
    if (acces == -1) {
        mysh->conc = my_strcat(my_strcat(tmp, "/"), mysh->args[0]);
        (access(mysh->conc, X_OK) == 0) ? (acces = 0) : (free(mysh->conc));
    }
    return acces;
}

int exec_cmd(stct_42sh_t *mysh, char **env)
{
    pid_t pid  = 0;
    int   fd   = 0;
    int status = 0;

    pid = fork();
    if (pid == 0)
        fd = execve(mysh->conc, mysh->args, env);
    else if (waitpid(pid, &status, F_OK)) {
        if (fd == -1)
            exit(0);
        (status == 11)  ? (SEG_FT) : (0);
        (status == 139) ? (CORE_D) : (0);
    }
    free(mysh->conc);
    return 0;
}

void cmd_not_found(stct_42sh_t *mysh)
{
    for (int i = 0; mysh->args[0][i]; i++)
        write(2, &mysh->args[0][i], 1);
    ERR_CM;
}

void simple_exec(stct_42sh_t * mysh, char **env)
{
    mysh->args = str_tab(mysh->cmds, ' ');
    if (bultin(mysh) != 0) {
        if (strcmp(mysh->cmds, "exit") == 0)
            exit(0);
        if (cmd_to_path(mysh) == -1)
            cmd_not_found(mysh);
        else
            exec_cmd(mysh, env);
    }
    for (size_t i = 0; mysh->args[i]; i++)
        free(mysh->args[i]);
    free(mysh->args);
}
