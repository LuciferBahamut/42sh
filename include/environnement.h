/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** environnement
*/

#ifndef ENVIRONNEMENT_H_
#define ENVIRONNEMENT_H_

#include <stdlib.h>
#include <unistd.h>
#include "utility.h"
#include "mysh.h"
#include "cmd.h"

void env_stat(cmd_t *cmd, char ***envp);
bool check_arg_setenv(char *env);
void print_env(char **envp);
bool env_path_check(char **exec, char **envp);
char *strcat_env(char *dest, char *src);
void env(cmd_t *cmd, char **envp);
void my_setenv(cmd_t *cmd, char ***env);
void add_env(char ***env, char *name, char *contain);
void unset_env(char ***env, char **name);
void del_line(char ***env, int it, int size);

#endif