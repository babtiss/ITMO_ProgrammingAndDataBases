#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

class Polynomial {
public:
    Polynomial() {
        size = 1;
        coeff.resize(1);
    }

    Polynomial(int x1) {
        size = x1;
        coeff.resize(size);
    }

    Polynomial(int x1, vector<int> &v) {
        size = x1;
        coeff = v;
    };

    Polynomial(const Polynomial &Polynomial_) {
        size = (Polynomial_.size);
        coeff = (Polynomial_.coeff);
    };

    Polynomial &operator=(const Polynomial &Polynomial_) {
        size = Polynomial_.size;
        coeff = Polynomial_.coeff;
        return *this;
    };

    bool operator==(const Polynomial &Polynomial_) {
        return (size == Polynomial_.size and coeff == Polynomial_.coeff);
    };

    bool operator!=(const Polynomial &Polynomial_) {
        return !(size == Polynomial_.size and coeff == Polynomial_.coeff);
    };

    Polynomial operator+(const Polynomial &Polynomial_) {

        int sizef = max(size, Polynomial_.size);
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
    };

    Polynomial operator-(const Polynomial &Polynomial_) {

        int sizef = max(size, Polynomial_.size);
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
    };

    Polynomial &operator+=(const Polynomial &Polynomial_) {

        int sizef = max(size, Polynomial_.size);
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
    };

    Polynomial &operator-=(const Polynomial &Polynomial_) {

        int sizef = max(size, Polynomial_.size);
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
    };

    Polynomial operator*(const Polynomial &Polynomial_) {
        int sizef = size + Polynomial_.size - 1;
        Polynomial temp(sizef);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < Polynomial_.size; j++) {
                temp.coeff[i + j] = coeff[i] * Polynomial_.coeff[j];
            }
        }
        return temp;
    };

    Polynomial &operator*=(const Polynomial &Polynomial_) {
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
    };

    Polynomial operator/(const int a) {
        Polynomial temp(size);
        for (int i = 0; i < size; i++) {
            temp.coeff[i] = coeff[i] / a;
        }
        return temp;
    };

    Polynomial &operator/=(const int a) {

        for (int i = 0; i < size; i++) {
            coeff[i] /= a;
        }
        return *this;
    };

    // Такое....
    friend ostream & operator<<(ostream &os, const Polynomial &Polynomial_) {
        return os << Polynomial_.get() << endl;

    };


    int &operator[](int index) {
        return coeff[index];
    }




    ~Polynomial() {
        coeff.clear();
        coeff.shrink_to_fit();
    }


private:
    int size;
    vector<int> coeff;
    string get() const{
        string a;
        for (int i=0;i<size;i++){
            a+=to_string(coeff[i])+"x^"+to_string(i);
            if (i!=size-1){
                if (coeff[i]>0){
                    a+='+';
                }
                else{
                    a+='-';
                }
            }
        }
        return a;
    }
};


int main() {


    vector<int> v = {3, 2};
    vector<int> d = {8, 9, 10};

    Polynomial a1(2, v);
    Polynomial a2(3, d);
    stringstream s;

    cout << a1 <<endl;
    s << a1;

    return 0;
};
