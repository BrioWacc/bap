#include<iostream>

class Fahrzeug {
    int MaximalGeschwindigkeit;

public:
    Fahrzeug(int t) : MaximalGeschwindigkeit(t) {}

    void fahren() {
        std::cout << "fahren: " << this->MaximalGeschwindigkeit << std::endl;
    }

    void starten() {
        std::cout << "Fahrzeug starten" << std::endl;
    }
};

class Kran {
    int MaximalGewicht;
public:
    Kran(int w) : MaximalGewicht(w) {}

    void heben() {
        std::cout << "heben: " << this->MaximalGewicht << std::endl;
    }

    void starten() {
        std::cout << "Kran starten" << std::endl;
    }
};

class Kranfahrzeug : public Fahrzeug, public Kran {
public:
    Kranfahrzeug(int t, int w) : Fahrzeug(t), Kran(w) {}
};

int main() {
    Kranfahrzeug obj(105, 500);

    obj.fahren();
    obj.heben();

    obj.Fahrzeug::starten();
    obj.Kran::starten();

    return 0;
}
