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

void dir_change(cmd_t *cmd, char **envp);
void cd_logdir(char **envp);

#endif