#include <stdio.h>

int main() {
    // Записать сумму a+b в файл
    int a;
    int b;
    FILE *file;
    file = fopen("C:/Users/777/Desktop/ITMO/Programm 1 sem/3 block/12 lab/a+b", "w");

    scanf("%d %d", &a, &b);
    int c;
    c = a + b;
    fprintf(file, "Sum = %d",c);
    fclose(file);

}
