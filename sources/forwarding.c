/*
** EPITECH PROaECT, 2019
** REDIRECTION
** File description:
** Function of redirection
*/

#include "42sh.h"

void chevron_one(buffer_t *buffer, int a, int i)
{
    char *str;
    int    fd;

    if (buffer->two_arrays[a][i++] != NULL) {
        str = malloc(sizeof(char) * my_strlen(buffer->two_arrays[a][i]) + 1);
        str = buffer->two_arrays[a][i];
        fd  = open(str, O_TRUNC | O_CREAT | O_RDWR | O_RDONLY, S_IRWXU);
        dup2(fd, 1);
    }
}

void chevron_two(buffer_t *buffer, int a, int i)
{
    char *str;
    int    fd;

    if (buffer->two_arrays[a][i++] != NULL) {
        str = malloc(sizeof(char) * my_strlen(buffer->two_arrays[a][i]) + 1);
        str = buffer->two_arrays[a][i];
        fd  = open(str, O_CREAT | O_APPEND | O_RDWR | O_RDONLY, S_IRWXU);
        dup2(fd, 1);
    }
}

void chevron_direction(buffer_t *buffer, int a, int i)
{
    char *str;
    int    fd;

    if (buffer->two_arrays[a][i++] != NULL) {
        str = malloc(sizeof(char) * my_strlen(buffer->two_arrays[a][i]) + 1);
        str = buffer->two_arrays[a][i];
        fd  = open(str, O_RDONLY);
        dup2(fd, 0);
    }
}

void check_redirection(buffer_t *buffer, int a)
{
    for (size_t i = 0; buffer->two_arrays[a][i] != NULL; i++) {
        if (my_strncmp(buffer->two_arrays[a][i], ">\0", 2) == 0) {
            one_chevron(buffer, a, i);
            break;
        } else if (my_strncmp(buffer->two_arrays[a][i], ">>\0", 3) == 0) {
            two_chevron(buffer, a, i);
            break;
        } else if (my_strncmp(buffer->two_arrays[a][i], "<\0", 2) == 0
                || my_strncmp(buffer->two_arrays[a][i], "<<\0", 3) == 0) {
            chevron_left(buffer, a, i);
            break;
        }
    }
}
