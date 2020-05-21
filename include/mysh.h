/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** mysh
*/

#ifndef MYSH_H_
#define MYSH_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "type.h"
#include "utility.h"
#include "bin_exec.h"
#include "dir_change.h"
#include "cmd.h"

cmddata_t *ask_input(void);
void erase_space(char **line);
char **get_envpath(char **envp);
char **get_envpath2(char *line);
int mysh(cmd_t *cmd, char ***envp);
int mysh2(cmd_t *cmd, char ***envp);
int redirection(cmd_t *cmd, char ***envp);

#endif