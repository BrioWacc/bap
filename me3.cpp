#include<iostream>

class Animal {
public:
    virtual void sprechen() const = 0;
};

class Hund : public Animal {
public:
    void sprechen() const {
        std::cout << "Wau" << std::endl;
    }
};

class Katze : public Animal {
public:
    void sprechen() const {
        std::cout << "Miau" << std::endl;
    }
};

int main() {
    Hund h;
    Katze k;

    h.sprechen();
    k.sprechen();

    return 0;
}
