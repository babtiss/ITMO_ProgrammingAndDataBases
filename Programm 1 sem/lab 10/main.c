#include <stdio.h>

char string[100];
char string2[100];
int lenstr = 100;

int sumdigit(int a) {
    if (a == 0) {
        return 0;
    } else {
        return (a % 10) + sumdigit(a / 10);
    }
}

void delete_space(int tek_i, int new_i) {
    if (tek_i == lenstr) {
        return;
    }
    if (string[tek_i] == ' ' && string[tek_i - 1] == ' ') {
        delete_space(tek_i + 1, new_i);

    } else {
        string2[new_i] = string[tek_i];
        delete_space(tek_i + 1, new_i + 1);
    }

}

int main() {
    //4 Считаем сумму цифр рекурсивно
    printf("4)------------\n");
    int b;
    scanf("%d", &b);
    printf("%d", sumdigit(b));

    //5 Удаляем пробелы из строки
    printf("\n5)------------\n");
    printf("lenstr , str = ");
    scanf("%d\n", &lenstr);
    lenstr++;
    fgets(string, lenstr, stdin);
    printf("str = %s", string);

    int lenstr2;
    lenstr2 = lenstr;
    for (int i = 1; i < lenstr; i++) {
        if (string[i] == ' ' && string[i - 1] == ' ') {
            lenstr2--;
        }
    }

    delete_space(1, 1);
    string2[0] = string[0];
    printf("\n New_str = %s", string2);

}
