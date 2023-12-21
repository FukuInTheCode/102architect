/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "include/my.h"
#include "my.h"
#include <math.h>

static int error_handling(int argc, char **argv,
    my_matrix_t *vector, my_matrix_t *m)
{
    int error = 0;
    char *endptr = NULL;
    int i_save = 3;

    if (argc < 5)
        return 84;
    vector->arr[0][0] = strtod(argv[1], &endptr);
    if (endptr != argv[1] + strlen(argv[1]))
        return 84;
    vector->arr[1][0] = strtod(argv[2], &endptr);
    if (endptr != argv[2] + strlen(argv[2]))
        return 84;
    for (int i = i_save; i < argc && !error; i = i_save) {
        for (int j = 0; my_params[j] && !error && i_save < argc; j++)
            error |= my_params[j](argv + i_save, argc - i_save, &i_save, m);
        error |= 84 * (i == i_save);
    }
    return error;
}

static double suppr_zero(double a)
{
    char buf[100] = {0};

    snprintf(buf, 50, "%.2lf", a);
    if (!strncmp("-0.00", buf, 5))
        return -a;
    return a;
}

static int print_all(my_matrix_t *m, my_matrix_t *vector, my_matrix_t *res)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m->arr[i][j] = suppr_zero(m->arr[i][j]);
            (j != 2) && (m->arr[i][j] >= 0) &&
                printf("%.2lf   ", m->arr[i][j]);
            (j == 2) && printf("%.2lf\n", m->arr[i][j]);
            (j != 2) && (m->arr[i][j] < 0) &&
                printf("%.2lf  ", m->arr[i][j]);
        }
    }
    res->arr[0][0] = vector->arr[0][0] * m->arr[0][0] +
        vector->arr[1][0] * m->arr[0][1] + m->arr[0][2];
    res->arr[1][0] = vector->arr[0][0] * m->arr[1][0] +
        vector->arr[1][0] * m->arr[1][1] + m->arr[1][2];
    printf("(%.2lf, %.2lf) => (%.2lf, %.2lf)\n",
        suppr_zero(vector->arr[0][0]), suppr_zero(vector->arr[1][0]),
        suppr_zero(res->arr[0][0]), suppr_zero(res->arr[1][0]));
    return 0;
}

int main(int argc, char **argv)
{
    int error = 0;
    my_matrix_t vector = {3, 1,
        (double *[]){(double []){0.}, (double []){0.}, (double []){1.}}};
    my_matrix_t res = {3, 1,
        (double *[]){(double []){0.}, (double []){0.}, (double []){0.}}};
    my_matrix_t m = {3, 3, (double *[]){
        (double []){1., 0., 0.},
        (double []){0., 1., 0.},
        (double []){0., 0., 1.}}};

    error |= error_handling(argc, argv, &vector, &m);
    if (error)
        return error;
    print_all(&m, &vector, &res);
    return error;
}
