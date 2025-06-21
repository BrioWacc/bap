#include<iostream>

bool CheckIfNull(const void* p) {
    std::cout << "(const void* p): "; 
    return p == nullptr;
}

bool CheckIfNull(const int* p) {
    std::cout << "(const int* p): "; 
    return p == nullptr;
}

int main() {
    int* intPtr = nullptr;
    void* voidPtr = nullptr;
    
    std::cout << std::boolalpha;
    std::cout << CheckIfNull(voidPtr) << '\n'
              << CheckIfNull(intPtr) << std::endl;
    
    std::cout << CheckIfNull((void*) nullptr) << '\n'
              << CheckIfNull((int*) nullptr) << std::endl;

    return 0;
}
