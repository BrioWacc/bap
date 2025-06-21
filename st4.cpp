#include<iostream>
#include<memory>

class Tier {
public:
    ~Tier() {
        std::cout << "I am being free'd" << std::endl;
    }
};

int main() {
    std::shared_ptr<Tier> t1 = std::make_shared<Tier>();
   
    std::cout << "t1 will start to be another object in next line, making the internal counter of the previous obj go to 0 and prompting the deconstructor" << std::endl;
    t1 = std::make_shared<Tier>();

    return 0;
}
