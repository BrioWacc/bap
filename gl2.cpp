#include<iostream>

class Rechteck {
    short position;
    short groeße;
public:
    void setData(short position, short groeße) {
        this->position = position;
        this->groeße = groeße;
    }

    void setData(const Rechteck& other) {
        this->position = other.position;
        this->groeße = other.groeße;
    }

    void printRect() {
        std::cout << "Position: " << this->position << '\n' << "Größe: " << this->groeße << std::endl;
    }
};

int main() {
    Rechteck r1, r2;

    r1.setData(1, 2);
    r2.setData(3, 4);

    r1.printRect();
    r2.printRect();

    std::cout << '\n';

    r1.setData(r2);

    r1.printRect();
    r2.printRect();

    return 0;
}
