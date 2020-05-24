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
        pre_fork_execbin(cmd, envp, get_envpath(envp));
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

    cpy = get_execname(&cmd->m_arg[0]);
    output = execve(cpy, cmd->m_arg, envp);
    if (output == -1) {
        write(2, cmd->m_arg[0], my_strlen(cmd->m_arg[0]));
        write(2, ": ", 2);
        write(2, strerror(errno), my_strlen(strerror(errno)));
        write(2, "\n", 1);
    }
}

void ppath_fork_execbin(char *p_pa, cmd_t *cmd, char **envp, char **env_path)
{
    int output = 0;
    char *cpy = 0;

    output = execve(p_pa, cmd->m_arg, envp);
    if (output == -1) {
        write(2, cmd->m_arg[0], my_strlen(cmd->m_arg[0]));
        write(2, ": ", 2);
        write(2, strerror(errno), my_strlen(strerror(errno)));
        write(2, "\n", 1);
    }
}

void pre_fork_execbin(cmd_t *cmd, char **envp, char **env_path)
{
    char *p_path = NULL;

    if (env_path_check(&cmd->m_arg[0], env_path))
        fork_execbin(cmd, envp, env_path);
    else if (ppath(cmd->m_arg[0]) != NULL) {
        p_path = ppath(cmd->m_arg[0]);
        ppath_fork_execbin(p_path, cmd, envp, env_path);
    }
    else {
        write(2, cmd->m_arg[0], my_strlen(cmd->m_arg[0]));
        write(2, CMD_NOT_FOUND, my_strlen(CMD_NOT_FOUND));
    }
}

char *get_execname(char **param)
{
    int it = my_strlen((*param));
    char *str = 0;
    char *ptr = (*param);

    for (; (*param)[it] != '/' && it != -1; it--)
        addchar(&str, (*param)[it]);
    str[my_strlen((*param)) - it - 1] = '\0';
    str = my_revstr(str);
    (*param) = str;
    return (ptr);
}
