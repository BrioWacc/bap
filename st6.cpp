#include<iostream>

class A {
public:
    void aSpecificFunction() {
        std::cout << "only A does this" << std::endl;
    }

    void foo() {
        std::cout << "foo A" << std::endl;
    }
};

class B {
public:
    void bSpecificFunction() {
        std::cout << "only B does this" << std::endl;
    }

    void foo() {
        std::cout << "foo B" << std::endl;
    }
};

class C : public A, public B {};

int main() {
    C test;

    //Con
    //Ambiguity - Which foo should be called now???
    //test.foo()
    test.A::foo();
    test.B::foo();
    
    //Pro
    //C can use the functionality of A and B
    test.aSpecificFunction();
    test.bSpecificFunction();

    return 0;
}
