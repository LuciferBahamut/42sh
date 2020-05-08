/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** main
*/

#include "mysh.h"

int main(int argc, char **argv, char **envp)
{
    type_e type;
    char *line = 0;
    cmddata_t *data = 0;

    while (1) {
        write(1, "$> ", 3);
        data = ask_input();
        for (cmddata_t *ptr_d = data; ptr_d; ptr_d = ptr_d->m_next)
            cmd_exec(ptr_d->m_cmd, &envp);
    }
}

cmddata_t *ask_input(void)
{
    int nb_read = 0;
    size_t read_size = 0;
    char *line = 0;

    nb_read = getline(&line, &read_size, stdin);
    if (nb_read == -1)
        exit(0);
    line[nb_read - 1] = '\0';
    if (nb_read - 1 == 0)
        return (0);
    return (parsing_cmd(line));
}