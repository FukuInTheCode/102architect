/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "include/my.h"
#include "my.h"

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

int main(int argc, char **argv)
{
    int error = 0;
    my_matrix_t vector = {3, 1,
        (double *[]){(double []){0.}, (double []){0.}, (double []){0.}}};
    my_matrix_t m = {3, 3, (double *[]){
        (double []){1., 0., 0.},
        (double []){0., 1., 0.},
        (double []){0., 0., 1.}}};

    error |= error_handling(argc, argv, &vector, &m);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; printf("%lf\n", m.arr[i][j++]));
    return error;
}
