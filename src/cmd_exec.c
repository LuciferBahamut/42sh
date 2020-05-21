/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** cmd_exec
*/

//#include "cmd.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "mysh.h"

void cmd_exec(cmd_t *cmd, char ***envp)
{
    int status = 0;
    int save_stdin = dup(0);
    int save_stdout = dup(1);
    char buf = 0;

    if (!cmd)
        return;
    if (!cmd->m_next) {
        mysh(cmd, envp);
    } else {
        status = mysh2(cmd, envp);
    }
    dup2(save_stdin, 0);
    dup2(save_stdout, 1);
    close(save_stdin);
    close(save_stdout);
}

int mysh(cmd_t *cmd, char ***envp)
{
    switch (cmd->m_type) {
        case BIN:
            return (bin_exec(cmd, (*envp)));
        case CD:
            dir_change(cmd, (*envp));
            return (0);
        case ENV_STATEMENT:
            env_stat(cmd, envp);
            return (0);
        case EXIT:
            write(1, "exit\n", 5);
            exit(0);
    }
}

int mysh2(cmd_t *cmd, char ***envp)
{
    int status = 0;

    if (cmd->m_opp == e_AppOutput || cmd->m_opp == e_output) {
        status = red_output(cmd, envp);
    } else if (cmd->m_opp == e_AppInput || cmd->m_opp == e_input) {
        //status = red_input(cmd, envp);
    } else {
        switch (cmd->m_type) {
        case BIN:
            return (bin_exec2(cmd, envp));
        case CD:
            dir_change(cmd, (*envp));
            return (0);
        case ENV_STATEMENT:
            env_stat(cmd, envp); // env write ?
            return (0);
        case EXIT:
            write(1, "exit\n", 5);
            exit(0); // change for a value
        }
    }
    return (status);
}

int red_output(cmd_t *cmd, char ***envp)
{
    int save_stdout;
    int status = 0;
    int file = 0;

    save_stdout = dup(1);
    if (cmd->m_opp == e_AppOutput)
        file = open(cmd->m_exec, O_APPEND | O_WRONLY | O_CREAT); // ajouter les droits
    else
        file = open(cmd->m_exec, O_WRONLY | O_CREAT); // ajouter les droits
    if (file == -1) {
        write(2, cmd->m_exec, my_strlen(cmd->m_exec));
        write(2, ": ", 2);
        write(2, strerror(errno), my_strlen(strerror(errno)));
        write(2, "\n", 1);
        return (84);
    }
    dup2(file, 1);
    status = mysh2(cmd->m_next, envp);
    close(file);
    dup2(save_stdout, 1);
}

int bin_exec2(cmd_t *cmd, char ***envp)
{
    int status = 0;
    int pipefd[2];

    pipe(pipefd);
    if (fork() == 0) {
        close(pipefd[1]);
        dup2(pipefd[0], 0);
        fork_execbin(cmd, (*envp), get_envpath((*envp)));
        close(pipefd[0]);
        exit(0);
    } else {
        close(pipefd[0]);
        dup2(pipefd[1], 1);
        if (cmd->m_next)
            mysh2(cmd->m_next, envp);
        close(pipefd[1]);
        wait(&status);
    }
    exit_status(status);
    return (status);
}