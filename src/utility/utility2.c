/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** utility2
*/

#include "utility.h"

char **my_split(char *str, char *cb)
{
    char **split = 0;
    int count = 0;
    int pos = 0;

    for (int it = 0; str[it]; it++)
        for (int it_ = 0; cb[it_]; it_++)
            count += (cb[it_] == str[it]) ? 1 : 0;
    split = malloc(sizeof(char *) * (count + 2));
    for (int it = 0; it < count + 2; it++)
        split[it] = 0;
    for (int it = 0; str[it]; it++) {
        count = 0;
        for (int it_ = 0; cb[it_]; it_++)
            count += (cb[it_] == str[it]) ? 1 : 0;
        if (count != 0) {
            pos++;
            continue;
        }
        addchar(&split[pos], str[it]);
    }
    return (split);
}

void freetab(char **tab)
{
    for (int it = 0; tab[it]; it++)
        free(tab[it]);
    free(tab);
}

char *my_strdup(char *str)
{
    int size = my_strlen(str);
    char *new_str = malloc(sizeof(char) * (size + 1));

    for (int it = 0; str[it]; it++)
        new_str[it] = str[it];
    new_str[size] = '\0';
    return (new_str);
}

char *my_strcat(char *name, char *contain)
{
    char *str = malloc(sizeof(char) *
        (my_strlen(name) + my_strlen(contain) + 1));
    int pos = 0;

    str[my_strlen(name) + my_strlen(contain)] = '\0';
    for (; name[pos]; pos++)
        str[pos] = name[pos];
    for (int it = 0; contain[it]; it++)
        str[pos + it] = contain[it];
    return (str);
}

int tablen(char **tab)
{
    int it = 0;

    for (; tab[it]; it++) {}
    return (it);
}