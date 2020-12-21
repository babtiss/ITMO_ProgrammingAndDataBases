#include <stdio.h>

int main() {
    //4
    printf("4)--------------\n");
    printf("n = ");
    int r;
    scanf("%d", &r);
    int n = r + 1;
    int a[n];
    for (int i = 2; i < n; i++) {
        a[i] = 0;

    }
    printf("prime numbers before %d\n", n - 1);

    for (int i = 2; i < n; i++) {
        if (a[i] == 0) {
            printf("%d ", i);
            for (int j = i; j < n; j = j + i) {
                a[j] = 1;
            }
        }
    }
    //5
    printf("\n5)--------------\n");
    printf("Money, Annual interest rate, month = \n");
    int money, month;
    double air;
    scanf("%d %lf %d", &money, &air, &month);
    double b[month + 1];
    b[0] = money;
    for (int i = 1; i <= month; i++) {
        b[i] = b[i - 1] * (1.0 + air);
        printf("\n%lf ", b[i]);
    }
}
