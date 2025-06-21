#include<iostream>
#include<ctime>
#include<cstdlib>

void printMeasurements1(float* array, const size_t N) {
    std::cerr << '[';
    for(int i=0; i<N; ++i) {
        std::cerr << array[i] << ", "; 
    }
    std::cerr << ']';
}

void printMeasurements2(const float* array, const size_t N) { 
    std::cerr << '[';
    for(int i=0; i<N; ++i) {
        std::cerr << array[i] << ", "; 
    }
    std::cerr << ']';
}
void printMeasurements3(float* const array, const size_t N) {
    std::cerr << '[';
    for(int i=0; i<N; ++i) {
        std::cerr << array[i] << ", "; 
    }
    std::cerr << ']';
}
void printMeasurements4(const float* const array, const size_t N) {
    std::cerr << '[';
    for(int i=0; i<N; ++i) {
        std::cerr << array[i] << ", "; 
    }
    std::cerr << ']';
}

#define BIG 1000000
int main() {
    srand(time(nullptr)); 
    
    const size_t N = BIG;
    float f[BIG];

    for(int i=0; i<N; ++i) {
        f[i] = (float)rand() / RAND_MAX;
    }

    printMeasurements1(f, N);
 
    printMeasurements2((const float*) f, N);

    printMeasurements3((float* const) f, N);
    
    printMeasurements4((const float* const) f, N);

    return 0;
}
