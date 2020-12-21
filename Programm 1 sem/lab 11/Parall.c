#include "Parall.h"

struct Parallelogram Init(double a, double b, double sina) {
    struct Parallelogram parall;
    parall.A = a;
    parall.B = b;
    parall.sina = sina;
    return parall;
}


double S(struct Parallelogram parall) {
    return parall.A * parall.B * parall.sina;
}


double Perimetr(struct Parallelogram parall) {
    return 2 * (parall.A + parall.B);
}