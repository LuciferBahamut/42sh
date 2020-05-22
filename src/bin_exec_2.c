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
    return 0;
}

void exit_status(int status)
{
    if (WTERMSIG(status) == SIGABRT)
        my_puterror("Abort", 0);
    if ((WTERMSIG(status) == SIGSEGV) && ((WCOREDUMP(status))))
        my_puterror("Segmentation fault (core dumped)", 0);
    else if ((WTERMSIG(status) == SIGSEGV))
        my_puterror("Segmentation fault", 0);
    if (WTERMSIG(status) == SIGFPE)
        my_puterror("Floating exception", 0);
    else if ((WTERMSIG(status) == SIGFPE) && ((WCOREDUMP(status))))
        my_puterror("Floating exception (core dumped)", 0);
    if (WTERMSIG(status) == SIGTERM)
        my_puterror("Terminated", 0);
    if (WTERMSIG(status) == SIGKILL)
        my_puterror("Killed", 0);
    if (WTERMSIG(status) == SIGQUIT)
        my_puterror("Quit", 0);
    if (WTERMSIG(status) == SIGSTOP)
        my_puterror("Stopped", 0);
    if (WTERMSIG(status) == SIGILL)
        my_puterror("illegal hardware instruction", 0);
}