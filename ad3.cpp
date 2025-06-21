#include<iostream>
#include<typeinfo>

class Fahrzeug {
public:
    virtual void info() const = 0;
    virtual ~Fahrzeug() {}
};

class Type1 : public Fahrzeug {
public:
    void info() const {
        std::cout << "Ich bin ein Fahrzeug von Type1" << std::endl;
    }
};

class Type2 : public Fahrzeug {
public:
    void info() const {
        std::cout << "Ich bin ein Fahrzeug von Type2" << std::endl;
    }
};

class Type3 : public Fahrzeug {
public:
    void info() const {
        std::cout << "Ich bin ein Fahrzeug von Type3" << std::endl;
    }
};

void infoCaller(const Fahrzeug* f) {
    f->info();
    std::cout << "Typinfo: " << typeid(*f).name() << std::endl;
}

int main() {
    Type1* t1 = new Type1();
    Type2* t2 = new Type2();
    Type3* t3 = new Type3();
    
    infoCaller(t1); 
    infoCaller(t2);
    infoCaller(t3);

    if(dynamic_cast<const Type1*>(t1)){
        std::cout << "t1 ist vom Type Type1" << std::endl;
    } else {
        std::cout << "t1 ist nicht vom Type Type1" << std::endl;
    }

    return 0;
}
