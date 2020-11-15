/*
** EPITECH PROJECT, 2019
** 42SH
** File description:
** Macro for 42sh
*/

#ifndef _42_SH__
#define _42_SH__

// == > LIB.C INC
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

// == > DEFINE SEP VALUE
#define _SEMICOLON_ 0
#define DOUBLE_ANDS 1
#define DOUBLE_PIPE 2
#define SIMPLE_PIPE 3
#define SIMPLE_R_RD 4
#define SIMPLE_L_RD 5
#define DOUBLE_R_RD 6
#define DOUBLE_L_RD 7

// == > MESSAGE MACRO
#define PROMPT printf("╭─\033[0m\e[1m\e[31mThe_42sh\033[0m\e[1m\e[32m@epitech\n\033[0m╰ \033[0m\e[1m\e[31m→ \033[0m")
#define ERR_CM write(2, ": Command not found.\n", 21)
#define SEG_FT write(2, "Segmentation fault\n", 18)
#define CORE_D write(2, "Segmentation fault (core dumped)\n", 33)
#define NO_SFL write(2, ": No such file or directory.\n", 29)
#define NO_DIR write(2, ": Not a directory.\n", 19)

// == > SHELL STRUCT
typedef struct stct_42sh_s {
    char     **path;
    char      *cmds;
    char     **args;
    char      *conc;
    char      *exec;
    char   dir[256];
    size_t     size;
    char      **sep;
} stct_42sh_t;

// == > SEPARATOR INT
typedef struct value_sep_s {
    int  d_ands;
    int  d_pipe;
    int  s_pipe;
    int  s_r_rd;
    int  s_l_rd;
    int  d_r_rd;
    int  d_l_rd;
} value_sep_t;

// == > ACCES_EXEC.C
int    cmd_to_path(stct_42sh_t *mysh);
int    exec_cmd(stct_42sh_t *mysh, char **env);
void   simple_exec(stct_42sh_t * mysh, char **env);
void   cmd_not_found(stct_42sh_t *mysh);

// == > ENV_MANAGE.C
size_t my_setenv(stct_42sh_t *mysh);
size_t my_unsetenv(stct_42sh_t *mysh);
void   manage_env(stct_42sh_t *mysh, char **env);

// == > MY_CD.C
int    check_cd(stct_42sh_t *mysh);
int    main_cd(stct_42sh_t *mysh, int special, int i);
int    cd_special(stct_42sh_t *mysh, int i, char const *home_path);
int    cd_home(stct_42sh_t *mysh, size_t i);

// == > BULTIN_MANAGE.C
int    echo(stct_42sh_t *mysh);
void   no_flag_e(stct_42sh_t *mysh, int flag_n);
int    bultin(stct_42sh_t *mysh);

// == > CHECK_SEP.C
int    priority(value_sep_t *sep);
int    check_sep(char *str);
int    check_semicolon(char *str);
void   launch_parse(stct_42sh_t *mysh, char **env, char *sep);
void   exec_semicolon(stct_42sh_t *mysh, char **env);

// == > STR_TAB.C
char **str_tab(char const *str, char sp);

// == > MY_LIB.C
size_t my_strline(char **str);
char  *my_strcat(char *src01, char *src02);
int    check_path(char *str);
char  *format_input(char *arg);

#endif /* _42_SH__ */
