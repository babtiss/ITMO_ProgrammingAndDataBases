#include <stdio.h>
#include "Parall.h"

int main() {
    double sin, a, b;
    scanf("%lf %lf %lf", &sin, &a, &b);
    struct Parallelogram x = Init(a, b, sin);

    printf("P = %lf\n", Perimetr(x));
    printf("S = %lf", S(x));

}
