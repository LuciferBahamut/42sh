/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** cmd
*/

#ifndef CMD_H_
#define CMD_H_

#include <stdbool.h>
#include <stdio.h>
#include "type.h"
#include "utility.h"

typedef enum
{
    e_AppInput,
    e_input,
    e_AppOutput,
    e_output,
    e_pipe,
    e_NA
} opp_e;

struct cmd_s
{
    char *m_exec;
    char **m_arg;
    type_e m_type;
    opp_e m_opp;
    struct cmd_s *m_next;
    struct cmd_s *m_prev;
} typedef cmd_t;

struct cmddata_s
{
    struct cmddata_s *m_next;
    struct cmddata_s *m_prev;
    cmd_t *m_cmd;
} typedef cmddata_t;

cmddata_t *parsing_cmd(char *line);
void cmd_push(cmddata_t **data, cmd_t *cmd);
void cmd_debug(cmddata_t *data);
cmd_t *cmd_generate(char *line);
void cmd_add(cmd_t **main, cmd_t *node);
opp_e get_oppat(char *line, int size);
cmd_t *cmd_create(char *line, opp_e opp);
void erase_space(char **line);
bool is_erased(char *line, int it, char *new_line, int diff);
type_e get_type(char *line);
void cmd_swapopp(cmd_t *cmd);
void cmd_exec(cmd_t *cmd, char ***envp);
bool is_opp(char c);

#endif
