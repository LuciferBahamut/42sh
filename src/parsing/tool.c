/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** tool
*/

#include "cmd.h"

void cmd_add(cmd_t **main, cmd_t *node)
{
    cmd_t *ptr = (*main);

    if (!ptr) {
        (*main) = node;
    } else {
        (*main) = node;
        ptr->m_prev = node;
        node->m_next = ptr;
    }
}

opp_e get_oppat(char *line, int size)
{
    char opp = line[size];

    if (opp == '<') {
        if (line[size + 1] == '<')
            return (e_AppInput);
        return (e_input);
    } else if (opp == '>') {
        if (line[size + 1] == opp)
            return (e_AppOutput);
        return (e_output);
    }
    if (opp == '|')
        return (e_pipe);
    return (e_NA);
}

bool is_erased(char *line, int it, char *new_line, int diff)
{
    if (line[it] != ' ' && line[it] != '\t')
        return (false);
    if (it == 0)
        return (true);
    if (is_opp(line[it + 1]) || is_opp(line[it - 1]) || line[it + 1] == ' ' ||
        line[it + 1] == '\t' || line[it + 1] == '\0') {
        return (true);
    }
    if ((is_opp(new_line[it - diff - 1]) || new_line[it - diff - 1] == ' ' ||
        new_line[it - diff - 1] == '\t'))
        return (true);
    return (false);
}

static type_e get_type_bis(char *line)
{
    if (start_match("echo ", line))
        return (ECHO);
    return (BIN);
}

type_e get_type(char *line)
{
    if (start_match("cd ", line) || str_match("cd\n", line)
        || str_match("cd\0", line))
        return (CD);
    if (start_match("setenv", line) ||
        start_match("unsetenv", line ) ||
        str_match("env\n", line))
        return (ENV_STATEMENT);
    if (str_match("exit", line) || start_match("exit ", line))
        return (EXIT);
    return (get_type_bis(line));
}
