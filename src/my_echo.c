/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** my_echo
*/

#include "mysh.h"

void my_echo(cmd_t *cmd)
{
    for (int i = 1; cmd->m_arg[i] != NULL; i++) {
        if (cmd->m_arg[i + 1] != NULL)
            printf("%s ", cmd->m_arg[i]);
        else
            printf("%s\n", cmd->m_arg[i]);
    }
}
