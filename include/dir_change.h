/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** dir_change
*/

#ifndef DIR_CHANGE_H_
#define DIR_CHANGE_H_

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "utility.h"
#include "bin_exec.h"
#include "cmd.h"

/* FUNCTIONS */
//void dir_change(cmd_t *cmd, char **envp);
void dir_change(cmd_t *cmd, char ***envp);
void cd_logdir(char *path, char ***envp);
//void cd_logdir(char **envp);
int cd_mysrcmp(char const *s1, char const *s2);
int cd_setenv_lenght(char *str, char *str2);
int cd_go_back(char **envp[]/*, int pos*/);
int change_dir(char *path, char **envp[]);
char **cd_copy(char *envp[], int add, int *pos);

/* ERROR MESSAGES */
static const char CD_ARGS[] = "cd: Too many arguments.\n";
#endif
