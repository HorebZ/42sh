/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** semicolon
*/

#include "42sh.h"

void launch_parse(stct_42sh_t *mysh, char **env, char *sep)
{
    mysh->args = str_tab(sep, ' ');
    if (bultin(mysh) != 0) {
        if (cmd_to_path(mysh) == -1)
            cmd_not_found(mysh);
        else
            exec_cmd(mysh, env);
    }
    for (size_t i = 0; mysh->args[i]; i++)
        free(mysh->args[i]);
    free(mysh->args);
}

void exec_semicolon(stct_42sh_t *mysh, char **env)
{
    mysh->sep = str_tab(mysh->cmds, ';');
    for (int i = 0; mysh->sep[i]; i++) {
        mysh->sep[i] = format_input(mysh->sep[i]);
        launch_parse(mysh, env, mysh->sep[i]);
    }
}