/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <time.h>
    #include <limits.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <math.h>
    #include <stdlib.h>

    #include <criterion/criterion.h>
    #include <criterion/redirect.h>

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #include <SFML/GPUPreference.h>
    #include <SFML/Network.h>
    #include <SFML/OpenGL.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>

typedef int(*func)();

typedef struct {
    int m;
    int n;
    double **arr;
} my_matrix_t;

int multiply_matrices(my_matrix_t *, my_matrix_t *);
int t_param_f(char **, int, int *, my_matrix_t *);
int z_param_f(char **, int, int *, my_matrix_t *);
int r_param_f(char **, int, int *, my_matrix_t *);

static func const my_params[] = {
    t_param_f,
    z_param_f,
    r_param_f,
    NULL
};

#endif
