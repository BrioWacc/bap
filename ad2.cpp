#include<iostream>

class SoilAnimal {
public:
    virtual void info() = 0;
    virtual ~SoilAnimal() {};
};

class Bird {
public:
    virtual void info() = 0;
    virtual ~Bird() {};
};

class Lion : public SoilAnimal {
public:
    void info() override {
        std::cout << "Lion" << std::endl;
    }
};

class Tiger : public SoilAnimal {
public:
    void info() override {
        std::cout << "Tiger" << std::endl;
    }
};

class Pecker : public Bird {
public:
    void info() override {
        std::cout << "Pecker" << std::endl;
    }
};

class Vulture : public Bird {
public:
    void info() override {
        std::cout << "Vulture" << std::endl;
    }
};

class AnimalFactory {
public:
    virtual SoilAnimal* createSoilAnimal() = 0;
    virtual Bird* createBird() = 0;
    virtual ~AnimalFactory() {}
};

class ThemeOneFactory : public AnimalFactory {
public:
    SoilAnimal* createSoilAnimal() override {
        return new Lion();
    }

    Bird* createBird() override {
        return new Pecker();
    }
};

class ThemeTwoFactory : public AnimalFactory {
public:
    SoilAnimal* createSoilAnimal() override {
        return new Tiger();
    }

    Bird* createBird() override {
        return new Vulture();
    }
};

int main() {
    AnimalFactory* t1 = new ThemeOneFactory();
    AnimalFactory* t2 = new ThemeTwoFactory();

    SoilAnimal* sa1 = t1->createSoilAnimal();
    SoilAnimal* sa2 = t2->createSoilAnimal();

    Bird* b1 = t1->createBird();
    Bird* b2 = t2->createBird();

    sa1->info();
    sa2->info();

    b1->info();
    b2->info();

    return 0;
}
