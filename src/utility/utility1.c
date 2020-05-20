/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** utility1
*/

#include "utility.h"

bool start_match(char *src, char *cmp)
{
    if (src == 0)
        return (false);
    for (int it = 0; src[it] != '\0'; it++)
        if (src[it] != cmp[it])
            return (false);
    return (true);
}

bool str_match(char *src, char *cmp)
{
    if (src == 0)
        return (false);
    for (int it = 0; src[it]; it++)
        if (src[it] != cmp[it])
            return (false);
    return (true);
}

int my_strlen(char const *str)
{
    int it = 0;

    for (; str[it] != '\0'; it++) {}
    return (it);
}

void addchar(char **str, char c)
{
    char *new_str = 0;

    if ((*str) == 0) {
        (*str) = malloc(sizeof(char) * 2);
        (*str)[0] = c;
        (*str)[1] = '\0';
        return;
    }
    new_str = malloc(sizeof(char) * (my_strlen((*str)) + 2));
    for (int it = 0; (*str)[it]; it++)
        new_str[it] = (*str)[it];
    new_str[my_strlen((*str))] = c;
    new_str[my_strlen((*str)) + 1] = '\0';
    (*str) = new_str;
}

char *my_revstr(char *str)
{
    int size = my_strlen(str) - 1;
    int pos = 0;
    char tmp = 0;

    while (pos < size) {
        tmp = str[pos];
        str[pos] = str[size];
        str[size] = tmp;
        pos++;
        size--;
    }
    return (str);
}