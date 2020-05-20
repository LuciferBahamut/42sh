/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** split
*/

#include "cmd.h"

bool cmd_validate(char *line, int it);

char **cmd_split(char *line)
{
    char **tab = 0;
    char *cmd = 0;

    if (line[0] == '\0' || line[0] == '<' || line[0] == '>' || line[0] == '|')
        return (0);
    for (int it = 0; line[it]; it++) {
        if (!cmd_validate(line, it))
            return (0);
        if (is_fopp(line, &it)) {
            add_str(&tab, cmd);
            cmd = 0;
        } else
            addchar(&cmd, line[it]);
    }
    add_str(&tab, cmd);
    return (tab);
}

bool cmd_validate(char *line, int it)
{
    if (it == 0) {
        if (is_opp(line[it]) && line[it] != ';')
            return (false);
        return (true);
    }
    if (line[it] == '|' && ((is_opp(line[it + 1]) && line[it + 1] != ';') ||
        (is_opp(line[it - 1]) && line[it - 1] != ';') || line[it + 1] == '\0'))
        return (false);
    if (line[it] == '>' && ((is_opp(line[it - 1]) && line[it - 1] != '>') ||
        (is_opp(line[it + 1]) && line[it + 1] != '>') || line[it + 1] == '\0'))
        return (false);
    return (true);
}
