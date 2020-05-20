/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** bin_exec
*/

#ifndef BIN_EXEC_H_
#define BIN_EXEC_H_

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "utility.h"
#include "environnement.h"
#include "mysh.h"
#include "cmd.h"

/* FUNCTIONS */
int bin_exec(cmd_t *cmd, char **envp);
void fork_execbin(cmd_t *cmd, char **envp, char **env_path);
char *get_execname(char **param);
void exit_status(int status);
int bin_exec2(cmd_t *cmd, char **envp);

/* ERROR MESSAGES */
static const char CMD_NOT_FOUND[] = ": Command not found.\n";
static const char CORE_DUMP[] = " (core dumped)";

#endif
