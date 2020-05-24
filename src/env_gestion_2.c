/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** to stock function that could be usefull-desu
*/

#include "environnement.h"

int exe_checker(char *pathname)
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
    return (test);
}

char *pathmaker(char *start, char *end)
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
    return (rsl);
}

int isbar(char *bin, char *check)
{
    int i = 0;
    int pos = -1;

    if (check != NULL)
        return (pos);
    else {
        for (; bin[i] != '\0'; i++)
            if (bin[i] == '/')
                pos = i;
    }
    return (pos);
}

char *ppath(char *bin)
{
    struct stat sb;
    char *path = NULL;
    int i = 0;
    int pos = -1;

    if (exe_checker(pathmaker(getcwd(NULL, 0), bin)) == 0)
        return (pathmaker(getcwd(NULL, 0), bin));
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
        return (path);
    else
        return (NULL);
}
