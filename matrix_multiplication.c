/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int get_row(my_matrix_t *m, int j, double row[3])
{
    for (int i = 0; i < 3; i++)
        row[i] = m->arr[j][i];
    return 0;
}

static int get_col(my_matrix_t *m, int j, double col[3])
{
    for (int i = 0; i < 3; i++)
        col[i] = m->arr[i][j];
    return 0;
}

static double dot_product(double col[3], double row[3])
{
    return col[0] * row[0] + col[1] * row[1] + col[2] * row[2];
}

int multiply_matrices(my_matrix_t *a, my_matrix_t *b)
{
    my_matrix_t tmp = {a->m, a->n, (double *[]){
        (double []){a->arr[0][0], a->arr[0][1], a->arr[0][2]},
        (double []){a->arr[1][0], a->arr[1][1], a->arr[1][2]},
        (double []){a->arr[2][0], a->arr[2][1], a->arr[2][2]}
    }};
    double column[3] = {0};
    double row[3] = {0};

    for (int i = 0; i < 3; i++) {
        get_row(b, i, row);
        for (int j = 0; j < 3; j++) {
            get_col(&tmp, j, column);
            a->arr[i][j] = dot_product(column, row);
        }
    }
    return 0;
}
