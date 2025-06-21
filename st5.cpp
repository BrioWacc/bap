#include<iostream>
#include<string>
#include<memory>

class Parent {
public:
    //virtual deconstructor -> makes sure correct deconstructor will be called (when Child is being free'd, the deconstructor of Child will always be called first (lookup this issue or you will not understand how/when)
    Parent() = default;
    virtual ~Parent() = default;

    //control over copying -> no unnecessary duplicates
    Parent(const Parent& other) = delete;
    Parent& operator=(const Parent& other) = delete;

    virtual void speak() {
        std::cout << "Parent" << std::endl;
    }
};

class Child : public Parent {
    std::string name;
public:
    //initializer list -> makes sure values are set once and correct
    Child(std::string name) : name(name) {}
    
    //override -> helps against typos (if I type speek, the compiler will complain that there is not virtual function called speek)
    void speak() override {
        std::cout << "Child" << std::endl;
    }
};

int main() {
    //smart pointers -> take care of calling delete
    std::shared_ptr<Child> c = std::make_shared<Child>("Tom");
    c->speak();
    return 0;
}
