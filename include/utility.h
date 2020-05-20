/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** utility
*/

#ifndef UTILITY_H_
#define UTILITY_H_

#include <stdbool.h>
#include <stdlib.h>

bool start_match(char *src, char *cmp);
bool str_match(char *src, char *cmp);
int my_strlen(char const *str);
void addchar(char **dest, char c);
char *my_revstr(char *str);
char **my_split(char *str, char *cb);
char *my_strdup(char *str);
void freetab(char **tab);
char *my_strcat(char *name, char *contain);
int tablen(char **tab);
bool is_fopp(char *line, int *it);
void add_str(char ***tab, char *line);

#endif