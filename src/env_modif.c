/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** env_modif
*/

#include "environnement.h"

void add_env(char ***env, char *name, char *contain)
{
    int size = 0;
    char **new_env = 0;

    unset_env(env, &name);
    for (; (*env)[size]; size++) {}
    new_env = malloc(sizeof(char *) * (size + 2));
    new_env[size + 1] = 0;
    for (int it = 0; (*env)[it]; it++)
        new_env[it] = (*env)[it];
    new_env[size] = my_strcat(name, contain);
    (*env) = new_env;
}

void unset_env(char ***env, char **name)
{
    int size = 0;

    if ((*env) == 0)
        return;
    addchar(name, '=');
    for (; (*env)[size]; size++) {}
    for (int it = 0; (*env)[it]; it++) {
        if (start_match((*name), (*env)[it]))
            del_line(env, it, size - 1);
    }
}

void del_line(char ***env, int it, int size)
{
    char **new_env = malloc(sizeof(char *) * (size + 1));
    int less = 0;

    new_env[size] = 0;
    for (int it_ = 0; (*env)[it_]; it_++) {
        if (it_ == it) {
            less++;
            continue;
        }
        new_env[it_ - less] = (*env)[it_];
    }
    (*env) = new_env;
}