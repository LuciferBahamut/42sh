/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** environnement
*/

#ifndef ENVIRONNEMENT_H_
#define ENVIRONNEMENT_H_

#include <stdlib.h>
#include <unistd.h>
#include "utility.h"
#include "mysh.h"
#include "cmd.h"

/* FUNCTIONS */
void env_stat(cmd_t *cmd, char ***envp);
bool check_arg_setenv(char *env);
void print_env(char **envp);
bool env_path_check(char **exec, char **envp);
char *strcat_env(char *dest, char *src);
void env(cmd_t *cmd, char **envp);
void my_setenv(cmd_t *cmd, char ***env);
void add_env(char ***env, char *name, char *contain);
void unset_env(char ***env, char **name);
void del_line(char ***env, int it, int size);

/* ERROR MESSAGES */
// unsetenv
static const char UNSETENV_ARGS[] = "unsetenv: Too few arguments.\n";

// env
static const char ENV_ARGS[] = "env: Too many arguments.\n";

// setenv
static const char SETENV_ALPHANUM[] = "setenv: Variable name must contain";
static const char SETENV_ALPHANUM2[] = " alphanumeric characters.\n";
static const char SETENV_ARGS[] = "setenv: Too many arguments.\n";

#endif /* ENVIRONNEMENT_H_ */
