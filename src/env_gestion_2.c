/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** to stock function that could be usefull-desu
*/

#include "environnement.h"
#include <sys/stat.h>

// bin = ../a.out or a.out or ./a.out,      a.out can be anything (yep even a directorie) which is not found thank to the PATH.

int exe_checker(char *pathname) // will check if the thing pointed by pathname can be executed by execve. if it can it return 0 else return something > 0
{
    int test = 0;

    if (access(pathname, F_OK) != 0)
        test += 1;
    else {
        if (access(pathname, R_OK) != 0)
            test += 1;
        if (access(pathname, X_OK) != 0)
            test += 1;
    }
    return test;
}

char *pathmaker(char *start, char *end) // take in start the beging of an ABSOLUTE path and in end it's end... no need to understand more this function is complexe.
{
    int len1 = 0;
    int len2 = 0;
    char *rsl;
    int i = 0;
    int j = 0;
    int nb[3] = {[0 ... 2] = 0};

    for (; start[i] != '\0' && nb[1] >= 0; i++)
        nb[0] += (start[i] == '/') ? 1 : 0;
    for (; end[len2] != '\0'; len2 += 1)
        nb[1] += (end[len2] == '.' && end[(len2 + 1)] == '.'
                    && end[(len2 + 1)] == '/') ? 1 : 0;
    for (; start[len1] != '\0' && nb[2] != (nb[0] - nb[1]); len1 += 1)
        nb[2] += (start[(len1 + 1)] == '/') ? 1 : 0;
    rsl = (char *)malloc((len1 + len2 + 2) * sizeof(char));
    rsl[(len1 + len2 + 1)] = '\0';
    for (i = 0; i < len1; rsl[i] = start[i], i++);
    rsl[i++] = '/';
    for (j += (3 * nb[1]); end[j] != '\0'; rsl[i] = end[j], i++, j++);
    return rsl;
}

int isbar(char *bin, char *check) // return the position of a "/" or return -1
{
    int i = 0;
    int pos = -1;

    if (check != NULL)
        return pos;
    else {
        for (; bin[i] != '\0'; i++)
            if (bin[i] == '/')
                pos = i;
    }
    return pos;
}

char *ppath(char *bin) // only use for bin that can't be found with the PATH. basically return the path to the bin if it can be execve or return NULL if it can't.
{
    struct stat sb;
    char *path = NULL;
    int i = 0;
    int pos = -1;

    if (exe_checker(pathmaker(getcwd(NULL, 0), bin)) == 0)
        return pathmaker(getcwd(NULL, 0), bin);
    if (bin[0] == '.' && bin[1] == '/')
        if (exe_checker(pathmaker(getcwd(NULL, 0), (bin + 2))) == 0)
            path = pathmaker(getcwd(NULL, 0), (bin + 2));
    if (bin[0] == '/' && exe_checker(bin) == 0) {
        stat(bin, &sb);
        if (S_ISDIR(sb.st_mode) == 0)
            path = bin;}
    if (isbar(bin, path) != -1)
        path = pathmaker(getcwd(NULL, 0), bin);
    if (exe_checker(path) == 0)
        return path;
    else
        return NULL;
}

// exemple of how ppath can be use.

//        else if (ppath(cmds[i].bin) != NULL)
//            cmds[i].path = ppath(cmds[i].bin);
//        else
//            return not_found(cmds[i]);