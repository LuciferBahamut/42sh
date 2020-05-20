/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** bin_exec
*/

#include "bin_exec.h"

int bin_exec(cmd_t *cmd, char **envp)
{
    int status = 0;

    if (fork() == 0) {
        fork_execbin(cmd, envp, get_envpath(envp));
        exit(0);
    } else
        wait(&status);
    exit_status(status);
    return (status);
}

void fork_execbin(cmd_t *cmd, char **envp, char **env_path)
{
    int output = 0;
    char *cpy = 0;

    if (env_path_check(&cmd->m_arg[0], env_path)) {
        cpy = get_execname(&cmd->m_arg[0]);
        output = execve(cpy, cmd->m_arg, envp);
        if (output == -1) {
            write(2, cmd->m_arg[0], my_strlen(cmd->m_arg[0]));
            write(2, ": ", 2);
            write(2, strerror(errno), my_strlen(strerror(errno)));
            write(2, "\n", 1);
        }
    } else {
        write(2, cmd->m_arg[0], my_strlen(cmd->m_arg[0]));
        write(2, ": Command not found.\n", 21);
    }
    exit(output);
}

char *get_execname(char **param)
{
    int it = my_strlen((*param));
    char *str = 0;
    char *ptr = (*param);

    for (; (*param)[it] != '/' && it != -1; it--)
        addchar(&str, (*param)[it]);
    str[my_strlen((*param)) - it] = '\0';
    str = my_revstr(str);
    (*param) = str;
    return (ptr);
}

void exit_status(int status)
{
    if (WIFSIGNALED(status)) {
        if (status == 139)
            write(2, SEG_MSG, SEG_MSG_SIZE);
        else if (status == 136)
            write(2, FLOAT_MSG, FLOAT_MSG_SIZE);
        else
            write(2, SEG_MSG, SEG_MSG_SIZE);
        if (WCOREDUMP(status))
            write(2, " (core dumped)", 14);
        write(2, "\n", 1);
    }
}