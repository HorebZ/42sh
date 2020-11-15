/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** Secondary project of shell programing module
*/

#include "42sh.h"

void i_want_to_break_free(stct_42sh_t *mysh, char **env)
{
    if (env[0] != NULL)
        for (size_t j = 0; mysh->path[j]; j++)
            free(mysh->path[j]);
    free(mysh->cmds);
    free(mysh->path);
}

int my_42(stct_42sh_t *mysh, char **env)
{
    mysh->cmds = NULL;
    if (getline(&mysh->cmds, &mysh->size, stdin) == -1)
        return -1;
    mysh->cmds = format_input(mysh->cmds);
    if (mysh->cmds[0] == '\0')
        return 0;
    check_sep(mysh->cmds);
    if (check_semicolon(mysh->cmds) == 1)
        exec_semicolon(mysh, env);
    else
        simple_exec(mysh, env);
    return 0;
}

int main(int ac, char **av, char **env)
{
    stct_42sh_t mysh;
    (void)        ac;
    (void)        av;

    manage_env(&mysh, env);
    while (42) {
        PROMPT;
        if (my_42(&mysh, env) == -1)
            break;
        free(mysh.cmds);
    }
    i_want_to_break_free(&mysh, env);
    return 0;
}