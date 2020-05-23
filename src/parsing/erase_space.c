/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** erase_space
*/

#include "cmd.h"

void erase_space(char **line)
{
    int it = 0;
    int diff = 0;
    char *new_line = malloc(sizeof(char) * (my_strlen((*line)) + 1));

    for (char *ptr = (*line); ptr[it] != '\0'; it++) {
        if (is_erased(ptr, it, new_line, diff)) {
            diff++;
            continue;
        }
        new_line[it - diff] = ptr[it];
    }
    new_line[my_strlen((*line)) - diff] = '\0';
    if (new_line[my_strlen((*line)) - diff - 1] == ' ' ||
        new_line[my_strlen((*line)) - diff - 1] == '\t' ||
        new_line[my_strlen((*line)) - diff - 1] == ';')
        new_line[my_strlen((*line)) - diff -1] = '\0';
    if (new_line[0] == ' ' || new_line[0] == '\t')
        new_line = my_strdup(new_line + 1);
    (*line) = new_line;
}
