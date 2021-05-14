#include "kek.h"

Polynomial::Polynomial() {
    size = 0;
    coeff = {0};
}

Polynomial::Polynomial(const int x) {
    size = x;
    coeff.resize(size);
}

Polynomial::Polynomial(const int x, const std::vector<int> &v) {
    size = x;
    coeff = v;
}

Polynomial::Polynomial(const Polynomial &Polynomial_) {
    size = Polynomial_.size;
    coeff = Polynomial_.coeff;
}

Polynomial &Polynomial::operator=(const Polynomial &Polynomial_) {
    size = Polynomial_.size;
    coeff = Polynomial_.coeff;
    return *this;
}

bool Polynomial::operator==(const Polynomial &Polynomial_) {
    return (size == Polynomial_.size and coeff == Polynomial_.coeff);
}

bool Polynomial::operator!=(const Polynomial &Polynomial_) {
    return !(size == Polynomial_.size and coeff == Polynomial_.coeff);
}

Polynomial Polynomial::operator+(const Polynomial &Polynomial_) {

    int sizef = std::max(size, Polynomial_.size);
    Polynomial temp(sizef);

    if (size > Polynomial_.size) {
        for (int i = 0; i < Polynomial_.size; i++) {
            temp.coeff[i] = coeff[i] + Polynomial_.coeff[i];
        }
        for (int j = Polynomial_.size; j < sizef; j++) {
            temp.coeff[j] = coeff[j];
        }
    } else {
        for (int i = 0; i < size; i++) {
            temp.coeff[i] = coeff[i] + Polynomial_.coeff[i];
        }
        for (int j = size; j < sizef; j++) {
            temp.coeff[j] = Polynomial_.coeff[j];
        }
    }
    return temp;
}

Polynomial Polynomial::operator-(const Polynomial &Polynomial_) {

    int sizef = std::max(size, Polynomial_.size);
    Polynomial temp(sizef);

    if (size > Polynomial_.size) {
        for (int i = 0; i < Polynomial_.size; i++) {

            temp.coeff[i] = coeff[i] - Polynomial_.coeff[i];
        }
        for (int j = Polynomial_.size; j < sizef; j++) {
            temp.coeff[j] = coeff[j];
        }
    } else {
        for (int i = 0; i < size; i++) {
            temp.coeff[i] = coeff[i] - Polynomial_.coeff[i];
        }
        for (int j = size; j < sizef; j++) {
            temp.coeff[j] = -Polynomial_.coeff[j];
        }
    }
    return temp;
}

Polynomial &Polynomial::operator+=(const Polynomial &Polynomial_) {

    int sizef = std::max(size, Polynomial_.size);
    coeff.resize(sizef);
    size = sizef;
    if (size > Polynomial_.size) {
        for (int i = 0; i < Polynomial_.size; i++) {
            coeff[i] = coeff[i] + Polynomial_.coeff[i];
        }

    } else {
        for (int i = 0; i < size; i++) {
            coeff[i] = coeff[i] + Polynomial_.coeff[i];
        }
        for (int j = size; j < sizef; j++) {
            coeff[j] = Polynomial_.coeff[j];
        }
    }
    return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial &Polynomial_) {

    int sizef = std::max(size, Polynomial_.size);
    coeff.resize(sizef);
    size = sizef;
    if (size > Polynomial_.size) {
        for (int i = 0; i < Polynomial_.size; i++) {
            coeff[i] = coeff[i] - Polynomial_.coeff[i];
        }
    } else {
        for (int i = 0; i < size; i++) {
            coeff[i] = coeff[i] - Polynomial_.coeff[i];
        }
        for (int j = size; j < sizef; j++) {
            coeff[j] = -Polynomial_.coeff[j];
        }
    }
    return *this;
}

Polynomial Polynomial::operator*(const Polynomial &Polynomial_) {
    int sizef = size + Polynomial_.size - 1;
    Polynomial temp(sizef);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < Polynomial_.size; j++) {
            temp.coeff[i + j] = coeff[i] * Polynomial_.coeff[j];
        }
    }
    return temp;
}

Polynomial operator*(const int a, const Polynomial &Polynomial_) {
    Polynomial temp(Polynomial_.size);
    for (int i = 0; i < Polynomial_.size; i++) {
        temp.coeff[i] = Polynomial_.coeff[i] * a;
    }
    return temp;
}

Polynomial &Polynomial::operator*=(const Polynomial &Polynomial_) {
    int sizef = size + Polynomial_.size - 1;
    Polynomial temp(sizef);


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < Polynomial_.size; j++) {
            temp.coeff[i + j] = coeff[i] * Polynomial_.coeff[j];
        }
    }
    coeff.resize(sizef);
    size = sizef;
    for (int i = 0; i < sizef; i++) {
        coeff[i] = temp.coeff[i];
    }
    return *this;
}

Polynomial Polynomial::operator/(const int a) {
    Polynomial temp(size);
    for (int i = 0; i < size; i++) {
        temp.coeff[i] = coeff[i] / a;
    }
    return temp;
}

Polynomial &Polynomial::operator/=(const int a) {

    for (int i = 0; i < size; i++) {
        coeff[i] /= a;
    }
    return *this;
}

int &Polynomial::operator[](const int index) {
    return coeff[index];
}

int Polynomial::get_size() const {
    return size;
}


std::string Polynomial::get() const {
    std::string a;
    for (int i = 0; i < size; i++) {
        a += std::to_string(coeff[i]) + "x^" + std::to_string(i);
        if (i != size - 1) {
            if (coeff[i] > 0) {
                a += '+';
            } else {
                a += '-';
            }
        }
    }
    return a;
}

std::ostream &operator<<(std::ostream &out, const Polynomial &Polynomial_) {
    return out << Polynomial_.get() << std::endl;
}

std::istream &operator>>(std::istream &in, Polynomial &Polynomial_) {
    in >> Polynomial_.size;
    for (int i = 0; i < Polynomial_.size; i++) {
        in >> Polynomial_.coeff[i];
    }
    return in;
}