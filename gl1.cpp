#include<iostream>

class Tier {
    int groesse;

protected:
    Tier(int groesse) : groesse(groesse) {}

public:
    virtual void leben() = 0;
};

class Hund : public Tier {
public:
    Hund(int groesse) : Tier(groesse) {}

    void leben() override {
        std::cout << "Hund" << std::endl;
    }
};

class Katze : public Tier {
public:
    Katze(int groesse) : Tier(groesse) {}

    void leben() override {
        std::cout << "Katze" << std::endl;
    }
};

int main() {
    Katze k(5);
    Hund h(3);

    k.leben();
    h.leben();

    return 0;
}
