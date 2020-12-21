#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    //1. Конкатенция строк
    printf("1)\n");
    char *str1 = (char *) malloc(sizeof(char) * len);
    char *str2 = (char *) malloc(sizeof(char) * len);
    char *result1 = malloc(strlen(str1) + strlen(str2) + 1);
    printf("Enter s1 =");
    scanf("%s", str1);
    printf("Enter s2 =");
    scanf("%s", str2);
    strcpy(result1, str1);
    strcat(result1, str2);
    printf("'%s' + '%s' = '%s' \n", str1, str2, result1);

    //4. Сравнение первых n символов двух строк
    printf("4)\n");
    int n = 5;
    char *str3 = (char *) malloc(sizeof(char) * len);
    char *str4 = (char *) malloc(sizeof(char) * len);
    printf("Enter s3 =");
    scanf("%s", str3);
    printf("Enter s4 =");
    scanf("%s", str4);
    if (strncmp(str3, str4, n) == 0)
        puts("==");
    else
        puts("!=");

    //7. Определить длину строки.
    printf("7)\n");
    char *str5 = (char *) malloc(sizeof(char) * len);
    printf("Enter s5 =");
    scanf("%s", str5);
    printf("Length s5 = %d\n", strlen(str5));


    //10. Осуществить поиск в одной строке любого из множества символов, входящих во вторую строку.
    printf("10)\n");
    char *str6 = (char *) malloc(sizeof(char) * len);
    char *str7 = (char *) malloc(sizeof(char) * len);
    printf("Enter s6 =");
    scanf("%s", str6);
    printf("Enter s7 =");
    scanf("%s", str7);
    char *p;
    printf("Found coincidences:\n");
    for (p = str6; *p; ++p)
        if (strchr(str7, *p))
            printf("%c ", *p);
    printf("\n");

    //11. Определить длину отрезка одной строки, содержащего символы из множества символов, входящих во вторую строку.
    printf("11)\n");
    char *str8 = (char *) malloc(sizeof(char) * len);
    char *str9 = (char *) malloc(sizeof(char) * len);
    printf("Enter s8=");
    scanf("%s", str8);
    printf("Enter s9=");
    scanf("%s", str9);
    printf(" Length  = %d\n", strspn(str8, str9));


    return 0;
}