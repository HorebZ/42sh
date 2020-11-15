/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** Secondary project of shell programing module
*/

#include "42sh.h"

int priority(value_sep_t *sep)
{
    if (sep->d_ands == 1)
        return DOUBLE_ANDS;
    if (sep->d_pipe == 1)
        return DOUBLE_PIPE;
    if (sep->s_pipe == 1)
        return SIMPLE_PIPE;
    if (sep->s_r_rd == 1)
        return SIMPLE_R_RD;
    if (sep->s_l_rd == 1)
        return SIMPLE_L_RD;
    if (sep->d_r_rd == 1)
        return DOUBLE_R_RD;
    if (sep->d_l_rd == 1)
        return DOUBLE_L_RD;
    return -1;
}

void init_sep(value_sep_t *sep)
{
    sep->d_ands = 0;
    sep->d_pipe = 0;
    sep->s_pipe = 0;
    sep->s_r_rd = 0;
    sep->s_l_rd = 0;
    sep->d_r_rd = 0;
    sep->d_l_rd = 0;
}

int check_sep(char *str)
{
    value_sep_t sep;
    char bef;
    char aft;

    init_sep(&sep);
    for (size_t i = 0; str[i] != '\0'; i++)
        if (str[i] == ';')
            return _SEMICOLON_;
    for (size_t j = 0; str[j] != '\0'; j++) {
        bef = str[j - 1];
        aft = str[j + 1];
        (str[j] == '|') ? (sep.s_pipe = 1) : (0);
        (str[j] == '&' && aft == '&') ? (sep.d_ands = 1) : (0);
        (str[j] == '|' && aft == '|') ? (sep.d_pipe = 1) : (0);
        (str[j] == '>' && aft == '>') ? (sep.d_r_rd = 1) : (0);
        (str[j] == '<' && aft == '<') ? (sep.d_l_rd = 1) : (0);
        (str[j] == '>' && aft != '>' && bef != '>') ? (sep.s_r_rd = 1) : (0);
        (str[j] == '<' && aft != '<' && bef != '<') ? (sep.s_l_rd = 1) : (0);
    }
    return priority(&sep);
}

int check_semicolon(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == ';')
            return 1;
    return 0;
}