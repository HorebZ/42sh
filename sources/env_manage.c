/*
** EPITECH PROJECT, 2019
** ENV_CFG
** File description:
** Fonction for cfg env
*/

#include "42sh.h"

size_t my_unsetenv(stct_42sh_t *mysh)
{
    int my_env;

    if (mysh->args[1] == NULL) {
        system("env");
        return 1;
    }
    my_env = unsetenv(mysh->args[1]);
    if (my_env != 0)
        return -1;
    return 1;
}

size_t my_setenv(stct_42sh_t *mysh)
{
    int my_env;

    if (mysh->args[1] == NULL || mysh->args[2] == NULL) {
        system("env");
        return 1;
    }
    my_env = setenv(mysh->args[1], mysh->args[2], 1);
    if (my_env != 0)
        return -1;
    return 1;
}

void flood_path(stct_42sh_t *mysh)
{
    char buffer[1000] = {0};

    mysh->path    = malloc(sizeof(char *) * 6);
    mysh->path[0] = "/usr/local/bin";
    mysh->path[1] = "/usr/local/sbin";
    mysh->path[2] = "/usr/bin";
    mysh->path[3] = "/usr/sbin";
    mysh->path[4] = getcwd(buffer, 1000);
    mysh->path[5] = NULL;
}

void manage_env(stct_42sh_t *mysh, char **env)
{
    size_t i = 0;
    char    *tmp;

    if (env[0] == NULL)
        flood_path(mysh);
    else {
        for (; env[i] != NULL && check_path(env[i]) != 0; i++);
        if (check_path(env[i]) == 0) {
            tmp = env[i] + 5;
            mysh->path = str_tab(tmp, ':');
        } else
            flood_path(mysh);
    }
}
