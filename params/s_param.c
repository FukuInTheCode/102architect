/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int print_name(double a)
{
    printf("Reflection over an axis with an inclination angle of ");
    if(fabs(round(a) - a) < 1e-2)
        printf("%d degrees\n", (int)round(a));
    else
        printf("%.2lf degrees\n", a);
    return 0;
}

int s_param_f(char **argv, int argc, int *i, my_matrix_t *m)
{
    my_matrix_t tmp = {3, 3, (double *[]){
        (double []){1, 0, 0},
        (double []){0, 1, 0},
        (double []){0, 0, 1}
        }};
    char *endptr = NULL;
    double angle;

    if (strcmp("-s", *argv))
        return 0;
    if (argc < 2)
        return 84;
    angle = strtod(argv[1], &endptr) * M_PI / 180. * 2.;
    if (argv[1] + strlen(argv[1]) != endptr)
        return 84;
    tmp.arr[0][0] = cos(angle);
    tmp.arr[0][1] = sin(angle);
    tmp.arr[1][0] = sin(angle);
    tmp.arr[1][1] = -1 * cos(angle);
    print_name(angle * 180. / M_PI / 2.);
    multiply_matrices(m, &tmp);
    *i += 2;
    return 0;
}
