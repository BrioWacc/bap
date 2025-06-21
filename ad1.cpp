#include<iostream>

class Bruch {
    int nenner;
    int zahler;
public:
    Bruch(int nenner, int zahler) : nenner(nenner), zahler(zahler) {}

    Bruch operator*(const Bruch& other) const {
        Bruch b(this->nenner * other.nenner, this->zahler * other.zahler);

        return b;
    }

    friend std::ostream& operator<<(std::ostream& os, const Bruch& b) {
        os << b.zahler << '/' << b.nenner;

        return os;
    }
};

int main() {
    Bruch b1(5, 6), b2(3, 8);

    std::cout << b1 << " * " << b2 << " = " << b1 * b2 << std::endl;
    return 0;
}
