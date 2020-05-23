/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** dir_change
*/

#include "dir_change.h"

int cd_mysrcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return ((s1[i] - s2[i]));
    return (0);
}

char *cd2(char *folder, char *envp[])
{
    int pos = 0;
    int len1 = 0;
    int len2 = 0;
    char *tmp = NULL;
    char *rsl = NULL;
    int i = 0;

    for (; envp[pos] != NULL && cd_mysrcmp(envp[pos], "HOME=\0") != 0; pos++);
    if (cd_mysrcmp(envp[pos], "HOME=\0") == 0)
        tmp = (envp[pos] + 5);
    for (; folder[len1] != '\0'; len1 += 1);
    for (; tmp[len2] != '\0'; len2 += 1);
    rsl = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    rsl[(len1 + len2)] = '\0';
    for (; tmp[i] != '\0'; rsl[i] = tmp[i], i++);
    rsl[i++] = '/';
    pos = (folder[1] == '\0') ? 1 : 2;
    for (; folder[pos] != '\0'; rsl[i] = folder[pos++], i++);
    return (rsl);
}

char *cd3(char *envp[])
{
    int pos = 0;
    char *tmp = NULL;

    for (; envp[pos] != NULL && cd_mysrcmp(envp[pos], "HOME=\0") != 0; pos++);
    if (cd_mysrcmp(envp[pos], "HOME=\0") == 0)
        tmp = (envp[pos] + 5);
    if (tmp != NULL)
        return (tmp);
    else
        return ("/home\0");
}

void dir_change(cmd_t *cmd, char ***envp)
{
    int output = tablen(cmd->m_arg);

    if (output > 2) {
        write(2, CD_ARGS, my_strlen(CD_ARGS));
        return;
    } else if (output == 1 || str_match("~\0", cmd->m_arg[1])) {
        if (output == 2)
            cd_logdir(cd2(cmd->m_arg[1], envp[0]), envp);
        else
            cd_logdir(cd3(envp[0]), envp);
        return;
    }
    if (output == 2 && str_match("-\0", cmd->m_arg[1])) {
        cd_go_back(envp);
        return;
    }
    output = change_dir(cmd->m_arg[1], envp);
    if (output == -1) {
        write(2, cmd->m_arg[1], my_strlen(cmd->m_arg[1]));
        write(2, ": ", 2);
        write(2, strerror(errno), my_strlen(strerror(errno)));
        write(2, ".\n", 2);
    }
}

void cd_logdir(char *path, char ***envp)
{
    int pos = 0;

    change_dir(path, envp);
    for (; envp[0][pos]; pos++)
        if (start_match(envp[0][pos], "LOGNAME="))
            break;
    if (envp[0][pos] != NULL)
        change_dir((envp[0][pos] + 8), envp);
}
