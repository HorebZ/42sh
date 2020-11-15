/*
** EPITECH PROJECT, 2019
** MY_LIB
** File description:
** personnal lib function
*/

#include "42sh.h"

size_t my_strline(char **str)
{
    size_t i = 0;

    for (; str[i]; i++);
    return i;
}

char *my_strcat(char *src01, char *src02)
{
    size_t i   = 0;
    size_t l01 = strlen(src01);
    size_t l02 = strlen(src02);
    char  *tmp = malloc(sizeof(char) * (l01 + l02 + 1));

    for (size_t y = 0; src01[y]; y++, i++)
        tmp[i] = src01[y];
    for (size_t j = 0; src02[j]; j++, i++)
        tmp[i] = src02[j];
    tmp[i++] = '\0';
    return tmp;
}

int check_path(char *str)
{
    char *str_cmp = "PATH=";

    for (int i = 0; str_cmp[i] != '\0'; i++) {
        if (str[i] != str_cmp[i])
            return 1;
    }
    return 0;
}

char *format_input(char *arg)
{
    size_t j  = 0;
    size_t i  = 0;
    char  *str_cp = malloc(sizeof(char) * strlen(arg) + 1);

    for (; arg[j] == ' ' || arg[j] == 9; j++);
    for (; arg[j] != '\0'; i++, j++) {
        if ((arg[j] == '\n') || ((arg[j] == ' ' ||
            arg[j] == 9) && arg[j + 1] == '\0')) {
            str_cp[i] = '\0';
            return str_cp;
        } if ((arg[j] == ' ' || arg[j] == 9) && arg[j + 1] > ' ') {
            str_cp[i] = ' ';
            continue;
        } if ((arg[j] == ' ' || arg[j] == 9) && arg[j + 1] <= ' ') {
            i--;
            continue;
        }
        str_cp[i] = arg[j];
    } str_cp[i] = '\0';
    return str_cp;
}