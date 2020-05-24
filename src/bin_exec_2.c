/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** error handling for execve-desu
*/

#include "bin_exec.h"

static void my_charerror(char e)
{
    write (2, &e, 1);
}

static int my_puterror(char *str, int opt)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        my_charerror(str[i]);
    if (opt == 0)
        my_charerror('\n');
    else if (opt == 1)
        my_charerror(' ');
    return (0);
}

static void exit_status_bis(int status)
{
    switch (WTERMSIG(status)) {
    case SIGKILL :
        my_puterror("Killed", 0);
        break;
    case SIGQUIT :
        my_puterror("Quit", 0);
        break;
    case SIGSTOP :
        my_puterror("Stopped", 0);
        break;
    case SIGILL :
        my_puterror("illegal hardware instruction", 0);
        break;
    }
}

void exit_status(int status)
{
    switch (WTERMSIG(status)) {
    case SIGABRT :
        my_puterror("Abort", 0);
        break;
    case SIGSEGV :
        if (WCOREDUMP(status))
            my_puterror("Segmentation fault (core dumped)", 0);
        else
            my_puterror("Segmentation fault", 0);
        break;
    case SIGFPE :
        if (WCOREDUMP(status))
            my_puterror("Floating exception (core dumped)", 0);
        else
            my_puterror("Floating exception", 0);
        break;
    case SIGTERM :
        my_puterror("Terminated", 0);
        break;}
    exit_status_bis(status);
}
