/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** write the error
*/

#include "dir_change.h"

void write_error(cmd_t *cmd)
{
    write(2, cmd->m_arg[1], my_strlen(cmd->m_arg[1]));
    write(2, ": ", 2);
    write(2, strerror(errno), my_strlen(strerror(errno)));
    write(2, ".\n", 2);
}
