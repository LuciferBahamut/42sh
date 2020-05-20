/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** env_gestion2
*/

#include "environnement.h"
#include "mysh.h"

void env(cmd_t *cmd, char **envp)
{
    if (tablen(cmd->m_arg) == 1)
        print_env(envp);
    else
        write(2, ENV_ARGS, my_strlen(ENV_ARGS));
}

void my_setenv(cmd_t *cmd, char ***envp)
{
    int nb_arg = tablen(cmd->m_arg);

    if (!check_arg_setenv(cmd->m_arg[1])) {
        write(2, SETENV_ALPHANUM, my_strlen(SETENV_ALPHANUM));
        write(2, SETENV_ALPHANUM2, my_strlen(SETENV_ALPHANUM2));
        return;
    }
    if (nb_arg == 1) {
        print_env((*envp));
        return;
    }
    if (nb_arg == 2)
        add_env(envp, cmd->m_arg[1], "\0");
    else if (nb_arg == 3)
        add_env(envp, cmd->m_arg[1], cmd->m_arg[2]);
    else
        write(2, SETENV_ARGS, my_strlen(SETENV_ARGS));
}

char **get_envpath(char **envp)
{
    int nb_path = 1;
    int pos = 0;
    char *line = 0;
    char **tab = 0;

    for (int it = 0; envp[it]; it++)
        if (start_match("PATH=", envp[it])) {
            line = envp[it];
            break;
        }
    if (line == 0)
        return (0);
    return (my_split(line, ":"));
}
