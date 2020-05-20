/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** utility3
*/

#include "utility.h"

bool is_opp(char c)
{
    if (c == '<' || c == '>' || c == '|' || c == ';')
        return (true);
    return (false);
}

bool is_fopp(char *line, int *it)
{
    if (line[(*it)] == '<') {
        if (line[(*it)] == '<')
            (*it)++;
        (*it)++;
        return (true);
    } else if (line[(*it)] == '>') {
        if (line[(*it)] == '>')
            (*it)++;
        (*it)++;
        return (true);
    }
    if (line[(*it)] == '|' || line[(*it)] == '&' ||
        line[(*it)] == ';') {
        (*it)++;
        return (true);
    }
    return (false);
}

void add_str(char ***tab, char *line)
{
    int size = 0;
    char **ntab = 0;

    if (!(*tab))
        size = 0;
    else
        size = tablen((*tab));
    ntab = malloc(sizeof(char *) * (size + 2));
    ntab[size + 1] = 0;
    if ((*tab)) {
        for (int it = 0; (*tab)[it]; it++)
            ntab[it] = (*tab)[it];
        free((*tab));
    }
    ntab[size] = line;
    (*tab) = ntab;
}