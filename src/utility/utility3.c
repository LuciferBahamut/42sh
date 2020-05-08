/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** utility3
*/

#include "utility.h"

bool is_opp(char c)
{
    if (c == '<' || c == '>' || c == '|' || c == ';')
        return (true);
    return (false);
}