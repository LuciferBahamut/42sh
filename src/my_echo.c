/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** my_echo
*/

#include "mysh.h"

static void my_putchar(char c)
{
    write(1, &c, 1);
}

static int myputstr(char *str, int opt)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    if (opt == 0)
        my_putchar('\n');
    else if (opt == 1)
        my_putchar(' ');
    return (0);
}

void my_echo(cmd_t *cmd)
{
    for (int i = 1; cmd->m_arg[i] != NULL; i++) {
        if (cmd->m_arg[i + 1] != NULL)
            myputstr(cmd->m_arg[i], 1);
        else
            myputstr(cmd->m_arg[i], 0);
    }
}
