/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** init
*/

#include "cmd.h"

cmddata_t *parsing_cmd(char *line)
{
    cmddata_t *data = 0;
    cmd_t *node = 0;
    char **split = 0;

    if (my_strlen(line) == 0)
        return (0);
    erase_space(&line);
    split = my_split(line, ";");
    for (int it = 0; split[it]; it++) {
        node = cmd_generate(split[it]);
        cmd_push(&data, node);
    }
    freetab(split);
    return (data);
}

cmd_t *cmd_generate(char *line)
{
    char **split = my_split(line, "<>|");
    cmd_t *cmd = 0;
    cmd_t *ncmd = 0;
    int size = 0;

    for (int it = 0; split[it]; it++) {
        if (my_strlen(split[it]) == 0) {
            size++;
            continue;
        }
        size += my_strlen(split[it]);
        ncmd = cmd_create(split[it], get_oppat(line, size));
        size++;
        cmd_add(&cmd, ncmd);
    }
    free(split);
    return (cmd);
}

cmd_t *cmd_create(char *line, opp_e opp)
{
    cmd_t *cmd = malloc(sizeof(cmd_t));

    cmd->m_arg = my_split(line, " \t");
    cmd->m_exec = my_strdup(cmd->m_arg[0]);
    cmd->m_type = get_type(line);
    cmd->m_opp = opp;
    cmd->m_next = 0;
    cmd->m_prev = 0;
    return (cmd);
}

void cmd_push(cmddata_t **data, cmd_t *cmd)
{
    cmddata_t *ptr = (*data);

    if (!ptr) {
        (*data) = malloc(sizeof(cmddata_t));
        ptr = (*data);
    } else {
        for (; ptr->m_next; ptr = ptr->m_next) {}
        ptr->m_next = malloc(sizeof(cmddata_t));
        ptr = ptr->m_next;
    }
    ptr->m_next = 0;
    ptr->m_prev = 0;
    ptr->m_cmd = cmd;
    cmd_swapopp(cmd);
}

void cmd_swapopp(cmd_t *cmd)
{
    opp_e opp = e_NA;

    for (cmd_t *ptr_c = cmd; ptr_c; ptr_c = ptr_c->m_next) {
        if (!ptr_c->m_next)
            continue;
        opp = ptr_c->m_next->m_opp;
        ptr_c->m_next->m_opp = ptr_c->m_opp;
        ptr_c->m_opp = opp;
    }
}