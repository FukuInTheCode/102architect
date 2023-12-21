/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int t_param_f(char **argv, int argc, int *i, my_matrix_t *m)
{
    my_matrix_t tmp = {3, 3, (double *[]){
        (double []){1, 0, 0},
        (double []){0, 1, 0},
        (double []){0, 0, 1}
        }};
    char *endptr = NULL;

    if (strcmp("-t", *argv))
        return 0;
    if (argc < 3)
        return 84;
    tmp.arr[0][2] = strtod(argv[1], &endptr);
    if (endptr != argv[1] + strlen(argv[1]))
        return 84;
    tmp.arr[1][2] = strtod(argv[2], &endptr);
    if (endptr != argv[2] + strlen(argv[2]))
        return 84;
    multiply_matrices(m, &tmp);
    *i += 3;
    return 0;
}
