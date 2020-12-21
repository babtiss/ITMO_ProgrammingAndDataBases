#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main(){
    int a;
    double z1 =-100, z2 =- 100, rad;
    printf("arg = ");
    scanf("%d", &a);
    rad = PI * a / 180;
    // ОДЗ 1 функции + её значение
    if (((a%180 != 30) && (a % 180 != 90 ) && (a %180 != 150)))
        z1 = (sin(2*rad) + sin(5*rad) - sin(3*rad)) / (cos(rad) - cos(3*rad) + cos(5*rad));
    // ОДЗ 2 функции + её значение
    if ((a%60 != 30))
        z2 =  tan(3*rad);

    if (z1 != -100)
        printf("z1 = %f\n", z1);
    else
        printf("argument out of range\n");
    if (z2 != -100)
        printf("z2 = %f", z2);
    else
        printf("argument out of range");

}
