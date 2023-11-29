/* Esercizio:
   lavora con puntatori a funzioni per implementare una funzione num_apply
   per manipolare ogni elemento di un array di double */

#include <stdio.h>
#include <math.h>
#include <stddef.h>

typedef double (*function)(double);

void num_apply(function func, void *arr, size_t dim) {
    for (size_t i = 0; i < dim; i++)
        ((double*)arr)[i] = func(((double*)arr)[i]);
}

double sqr(double x) { return x * x; }
double mult2(double x) { return 2 * x; }

int main() {
    double dary[] = {4, 16, 36};
    size_t n = sizeof dary / sizeof dary[0];

    printf("Original Array: {%lf, %lf, %lf}\n", dary[0], dary[1], dary[2]);

    num_apply(sqrt, dary, n);
    printf("Modified Array after sqrt: {%lf, %lf, %lf}\n", dary[0], dary[1], dary[2]);

    num_apply(mult2, dary, n);
    printf("Modified Array after sqr: {%lf, %lf, %lf}\n", dary[0], dary[1], dary[2]);

    num_apply(sqr, dary, n);
    printf("Modified Array after mult2: {%lf, %lf, %lf}\n", dary[0], dary[1], dary[2]);

    return 0;
}