#include<iostream>

template<typename T>
void print(const T& t) {
    std::cout << t << std::endl;
};

template<typename T, int N>
struct array_t {
    T arr[N];
    int n = N;

    T& operator[](int index) {
        return this->arr[index];
    }
    
    const T& operator[](int index) const {
        return this->arr[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const array_t& a) {
        os << '[';
        for(int i=0; i<a.n; ++i) os << a[i] << ", ";
        os << ']';
        
        return os;
    }
};

int main() {
    array_t<int, 5> arr({1, 2, 3, 4, 5});

    print<array_t<int, 5>>(arr);

    return 0;
}
