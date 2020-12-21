#include <stdio.h>

#include <locale.h>

int main(){
    setlocale(LC_ALL, "Rus");

    int a, larger;
    scanf("%d", &a);
    larger = ((a >= 65) && (a <= 87)) ? 1 : 0;
    printf("%d\n", larger);


    int num;
    printf("Введите число в 10-ой системе счисления : ");
    scanf("%d", &num);
    printf("24-ый бит числа = %d", (num >> 24) % 2 );
}
