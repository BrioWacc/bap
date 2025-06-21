#include<iostream>

class BaseFigur {
protected:
    float length;
    float height;

public:
    BaseFigur(float length, float height) : length(length), height(height) {}
    virtual float calcArea() = 0;
};

class Rectangle : public BaseFigur {
public:
    Rectangle(float length, float height) : BaseFigur(length, height) {} 

    float calcArea() override {
        return this->length * this->height;
    }
};


class RightAngleTriangle : public BaseFigur {
public:
    RightAngleTriangle(float length, float height) : BaseFigur(length, height) {} 

    float calcArea() override {
        return this->length * this->height * 0.5;
    }
};

int main() {
    Rectangle r(5,2);
    RightAngleTriangle t(5,2);

    std::cout << "Rectangle: " << r.calcArea() << '\n' << "Triangle: " << t.calcArea() << std::endl;

    return 0;
}
