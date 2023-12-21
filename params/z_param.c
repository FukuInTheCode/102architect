/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int print_name(double a, double b)
{
    printf("Scaling by factors ");
    if(fabs(round(a) - a) < 1e-2)
        printf("%d and ", (int)round(a));
    else
        printf("%.2lf and ", a);
    if(fabs(round(b) - b) < 1e-2)
        printf("%d and \n", (int)round(b));
    else
        printf("%.2lf and \n", b);
    return 0;
}

int z_param_f(char **argv, int argc, int *i, my_matrix_t *m)
{
    my_matrix_t tmp = {3, 3, (double *[]){
        (double []){1, 0, 0},
        (double []){0, 1, 0},
        (double []){0, 0, 1}
        }};
    char *endptr = NULL;

    if (strcmp("-z", *argv))
        return 0;
    if (argc < 3)
        return 84;
    tmp.arr[0][0] *= strtod(argv[1], &endptr);
    if (endptr != argv[1] + strlen(argv[1]))
        return 84;
    tmp.arr[1][1] *= strtod(argv[2], &endptr);
    if (endptr != argv[2] + strlen(argv[2]))
        return 84;
    print_name(tmp.arr[0][0], tmp.arr[1][1]);
    multiply_matrices(m, &tmp);
    *i += 3;
    return 0;
}
