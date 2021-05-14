#pragma once

#include <sstream>
#include <iostream>
#include <vector>

class Polynomial {
public:
    Polynomial();

    Polynomial(const int);

    Polynomial(const int, const std::vector<int> &);

    Polynomial(const Polynomial &);

    int get_size() const;

    Polynomial &operator=(const Polynomial &);

    bool operator==(const Polynomial &);

    bool operator!=(const Polynomial &);

    Polynomial operator+(const Polynomial &);

    Polynomial operator-(const Polynomial &);

    Polynomial &operator+=(const Polynomial &);

    Polynomial &operator-=(const Polynomial &);

    Polynomial operator*(const Polynomial &);

    friend Polynomial operator*(const int a, const Polynomial &);

    Polynomial &operator*=(const Polynomial &);

    Polynomial operator/(const int);

    Polynomial &operator/=(const int);

    friend std::ostream &operator<<(std::ostream &, const Polynomial &);

    friend std::istream &operator>>(std::istream &, Polynomial &);

    int &operator[](const int);


private:
    int size;
    std::vector<int> coeff;

    std::string get() const;
};


