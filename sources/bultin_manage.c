/*
** EPITECH PROJECT, 2019
** BULTIN_MANAGEMENT
** File description:
** Bultin checker and echo and env manage
*/

#include "42sh.h"

int echo(stct_42sh_t *mysh)
{
    int flag_n = 0;

    if (strcmp(mysh->cmds, "echo") == 0) {
        printf("\n");
        return 1;
    }
    (mysh->args[1][0] == '-' && mysh->args[1][1] == 'n') ? (flag_n++) : (0);
    if (flag_n != 0)
        for (int i = 2; mysh->args[i]; i++)
            printf("%s ", mysh->args[i]);
    else if (flag_n == 0) {
        for (int i = 1; mysh->args[i]; i++)
            printf("%s ", mysh->args[i]);
        printf("%c", '\n');
    }
    return 1;
}

int bultin(stct_42sh_t *mysh)
{
    if (strcmp(mysh->args[0], "cd")         == 0) {
        check_cd(mysh);
        return 0;
    } if (strcmp(mysh->args[0], "env")      == 0) {
        system("env");
        return 0;
    } if (strcmp(mysh->args[0], "setenv")   == 0) {
        my_setenv(mysh);
        return 0;
    } if (strcmp(mysh->args[0], "unsetenv") == 0) {
        my_unsetenv(mysh);
        return 0;
    } if (strcmp(mysh->args[0], "echo")     == 0) {
        echo(mysh);
        return 0;
    } return -1;
}