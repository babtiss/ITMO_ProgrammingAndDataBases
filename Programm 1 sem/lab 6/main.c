#include <stdio.h>
#include <stdlib.h>


int main() {

    char mas[5]; // Массив mas
    char *p = mas; // Указатель на массив mas

    // Заполним массив mas с помощью указателя
    *(p + 0) = 'H';
    *(p + 1) = 'e';
    *(p + 2) = 'l';
    *(p + 3) = 'l';
    *(p + 4) = 'o';

    for (int i = 0; i < 5; i++) {
        printf("%d) %d %c\n", i, p[i], p[i]);
    }
    printf("\n");

    int *A = (int *) malloc(5 * sizeof(int)); // Динамический массив

    for (int i = 0; i < 5; i++) {
        A[i] = i;
        printf("%d ", A[i]);
    }
    free(A);
}
