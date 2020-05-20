/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** env_gestion
*/

#include "environnement.h"

void env_stat(cmd_t *cmd, char ***envp)
{
    int nb_arg = tablen(cmd->m_arg);
    int validity = 0;

    if (str_match(cmd->m_exec, "env")) {
        env(cmd, (*envp));
    } else if (str_match(cmd->m_exec, "setenv")) {
        my_setenv(cmd, envp);
    }
    if (str_match(cmd->m_exec, "unsetenv")) {
        if (nb_arg == 1) {
            write(2, "unsetenv: Too few arguments.\n", 29);
            return;
        }
        for (int it = 1; cmd->m_arg[it]; it++)
            unset_env(envp, &cmd->m_arg[it]);
    }
}

bool check_arg_setenv(char *env)
{
    if (env == 0)
        return (true);
    for (int it = 0; env[it]; it++) {
        if ((env[it] >= 'A' && env[it] <= 'Z') ||
            (env[it] >= 'a' && env[it] <= 'z') ||
            (env[it] >= '0' && env[it] <= '9') ||
            env[it] == '.' || env[it] == '=')
            continue;
        return (false);
    }
    return (true);
}

void print_env(char **envp)
{
    for (int it = 0; envp[it]; it++) {
        write(1, envp[it], my_strlen(envp[it]));
        write(1, "\n", 1);
    }
}

bool env_path_check(char **exec, char **envp)
{
    char *path = 0;

    if (start_match((*exec), "./")) {
        if (access((*exec), F_OK) != -1)
            return (true);
        return (false);
    }
    if (envp == 0)
        return (false);
    for (int it = 0; envp[it]; it++)
        if (start_match((*exec), envp[it]))
            return (true);
    for (int it = 0; envp[it]; it++) {
        path = strcat_env(envp[it], (*exec));
        if (access(path, F_OK) != -1) {
            (*exec) = path;
            return (true);
        }
    }
    return (false);
}

char *strcat_env(char *dest, char *src)
{
    int size_dest = 0;
    int size_src = my_strlen(src);
    char *new = 0;

    if (dest == 0)
        size_dest = 0;
    else
        size_dest = my_strlen(dest);
    new = malloc(sizeof(char) * (size_dest + size_src + 2));
    new[size_src + size_dest + 1] = '\0';
    if (dest != 0)
        for (int it = 0; dest[it]; it++)
            new[it] = dest[it];
    new[size_dest] = '/';
    for (int it = 0; src[it]; it++)
        new[size_dest + 1 + it] = src[it];
    return (new);
}