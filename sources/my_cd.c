/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** Secondary project of shell programing module
*/

#include "42sh.h"

int main_cd(stct_42sh_t *mysh, int special, int i)
{
    struct stat buffer;
    int          error;

    if (special == 0) {
        error = stat(mysh->args[i + 1], &buffer);
        if (error != 0)
            dprintf(2, "%s: No such file or directory.\n", mysh->args[i + 1]);
        else {
            if (chdir(mysh->args[i + 1]) != 0) {
                dprintf(2, "%s", mysh->args[i + 1]);
                NO_DIR;
            }
        }
    } else
        return 1;
    return 0;
}

int cd_special(stct_42sh_t *mysh, int i, char const *home_path)
{
    if (mysh->args[i + 1] != NULL) {
        if (mysh->args[i + 1][0] == '-' && mysh->dir[0] != '\0') {
            dprintf(2, "%s\n", mysh->dir);
            chdir(mysh->dir);
            return 1;
        } if (mysh->args[i + 1][0] == '~' && mysh->args[i + 1][1] == '\0') {
            chdir(home_path);
            return 1;
        }
    }
    getcwd(mysh->dir, sizeof(mysh->dir));
    if (mysh->args[i + 1] == NULL) {
        chdir(home_path);
        return 1;
    }
    return 0;
}

int cd_home(stct_42sh_t *mysh, size_t i)
{
    int         special;
    char const *home_path = getenv("HOME");

    if (mysh->args[i][0] == 'c' && mysh->args[i][1] == 'd') {
        special = cd_special(mysh, i, home_path);
        if (main_cd(mysh, special, i) == 1)
            return 1;
    }
    return 0;
}

int check_cd(stct_42sh_t *mysh)
{
    static int cd_neg = 0;

    if (cd_neg == 0 && strcmp(mysh->cmds, "cd -") == 0) {
        NO_SFL;
        return 1;
    }
    cd_neg = 1;
    for (size_t i = 0; mysh->args[i] != NULL; i++)
        if (cd_home(mysh, i) == 1)
            return 1;
    return 1;
}
