#include<iostream>

class complexNumber {
public:
    float real;
    float imag;

    complexNumber(float real, float imag) : real(real), imag(imag) {}

    complexNumber operator+(const complexNumber& other) const {
        complexNumber obj(this->real + other.real, this->imag + other.imag);

        return obj;
    }

    friend std::ostream& operator<<(std::ostream& os, const complexNumber& cN) {
        os << "Real: " << cN.real << '\n' << "Imag: " << cN.imag << std::endl;

        return os;
    }
};

int main() {
    complexNumber cN1(5, 4.5), cN2(3.3, 5.9);

    std::cout << cN1 << '\n' << cN2 << '\n' << '+' << "\n\n" << cN1 + cN2 << std::endl;
    return 0;
}
