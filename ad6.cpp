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
    
    void* legacyVoidPtr = 0;
    int* legacyIntPtr = NULL;

    std::cout << CheckIfNull(legacyVoidPtr) << '\n'
              << CheckIfNull(legacyIntPtr) << std::endl;

    return 0;
}
