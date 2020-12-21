#include <stdio.h>
#include <stdlib.h>

int main() {

    // 1.Заполнение массива согласно варианту
    int mas[] = {12, 13, 14, 15, 16, 17, 18, 19, 20};
    for (int i = 0; i < 9; i++) {
        printf("%d ", mas[i]);
    }
    printf("\n");
            }
        }
    }
    for (int i = 0; i < 2; i++) {

    int matr1[2][2] = {2, 1, 1, 3};
    int matr2[2][2] = {1, 2, 3, 1};
    int matr3[2][2] = {0, 0, 0, 0};

    // 2.Перемножение матриц 2*2
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int z = 0; z < 2; z++) {
                matr3[i][j] += matr1[i][z] * matr2[z][j];

        for (int j = 0; j < 2; j++) {
            printf("%d ", matr3[i][j]);
        }
        printf("\n");
    }


}