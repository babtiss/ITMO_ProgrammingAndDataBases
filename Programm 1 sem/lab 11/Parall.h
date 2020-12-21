#ifndef UNTITLED_PARALL_H
#define UNTITLED_PARALL_H

struct Parallelogram {
    double A;
    double B;
    double sina;
};

struct Parallelogram Init(double a, double b, double sin);

double S(struct Parallelogram);

double Perimetr(struct Parallelogram);

#endif //UNTITLED_PARALL_H
