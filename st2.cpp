#include<iostream>

class myEcard {
    static myEcard* singleton;

    myEcard() {};
public:
    static myEcard* get(){
        if(singleton == nullptr) singleton = new myEcard;
        return singleton;
    }
};

myEcard* myEcard::singleton = nullptr;

int main() {
    myEcard* e1 = myEcard::get();
    myEcard* e2 = myEcard::get();

    std::cout << e1 << '\n' << e2 << std::endl;

    return 0;
}
