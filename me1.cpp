#include<iostream>
#include<exception>
#include<cstdlib>
#include<string>

class NotANumberException : public std::exception {
public: 
    const char* what() const noexcept override {
        return "This is not a number";
    }
};

class NotInRangeException : public std::exception {
    const char* msg;
public:
    NotInRangeException(const char* msg) : msg(msg) {}

    const char* what() const noexcept override {
        return msg;
    }
};

int isNumber(const char* s) {
    for(int i=0; s[i]!='\0'; ++i) if(s[i] < '0' || '9' < s[i]) return 0; 
    
    return 1;
}

int main() {
    try {
        std::string msg;
        std::cout << "\nEnter a value: ";
        std::getline(std::cin >> std::ws, msg);

        if(!isNumber(msg.c_str())) throw NotANumberException();

        int value = atoi(msg.c_str());

        if(value < 1 || 10 < value) throw NotInRangeException("Number is not between 1 and 10");

        std::cout << "No Exceptions thrown" << std::endl;
    }
    catch(NotANumberException& e) {
        std::cerr << e.what() << std::endl;
    }
    catch(NotInRangeException& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
