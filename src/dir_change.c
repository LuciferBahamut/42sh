/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** dir_change
*/


#include "dir_change.h"

void dir_change(cmd_t *cmd, char **envp)
{
    int output = tablen(cmd->m_arg);

    if (output > 2) {
        write(2, CD_ARGS, my_strlen(CD_ARGS));
        return;
    } else if (output == 1 || str_match(cmd->m_arg[1], "~")) {
        cd_logdir(envp);
        return;
    }
    output = chdir(cmd->m_arg[1]);
    if (output == -1) {
        write(2, cmd->m_arg[1], my_strlen(cmd->m_arg[1]));
        write(2, ": ", 2);
        write(2, strerror(errno), my_strlen(strerror(errno)));
        write(2, ".\n", 2);
    }
}

void cd_logdir(char **envp)
{
    int pos = 0;

    chdir("/home");
    for (; envp[pos]; pos++)
        if (start_match(envp[pos], "LOGNAME="))
            break;
    chdir(envp[pos] + 8);
}
