#include <stdio.h>

enum car {
    passenger, truck, bus, racing
};

struct rectangle {
    double length, width;

};
union Phone {
    struct Dictaphone {
        unsigned int pause: 1;
        unsigned int record: 1;
        unsigned int reproduction: 1;
    } dic;
    unsigned input;


} ph;


int main() {

    enum car answer1;
    answer1 = bus;
    printf("1) %d\n", answer1);

    struct rectangle pr;
    float a, b;
    printf("2) length rectangle = ");
    scanf("%f", &a);
    pr.length = a;
    printf("width rectangle = ");
    scanf("%f", &b);
    pr.width = b;
    printf("S = %f\n", a * b);
    printf("P = %f\n", 2 * (a + b));

    printf("3) X = ");
    scanf("%x", &ph.input);
    printf("Pause %s\n", ph.dic.pause ? "ON" : "OF");
    printf("Record %s\n", ph.dic.record ? "ON" : "OF");
    printf("Reproduction %s\n", ph.dic.reproduction ? "ON" : "OF");

}

