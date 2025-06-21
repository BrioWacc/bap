#include<iostream>
#include<vector>

using namespace std;

void print(vector<int>& v) {
    std::cout << '[';
    for(int i : v) std::cout << i << ", ";
    std::cout << ']' << std::endl;;
}

void print(vector<int>* v) {
    std::cout << '[';
    for(int i : (*v)) std::cout << i << ", ";
    std::cout << ']' << std::endl;
}

void modify(vector<int>& v, int& a) {
    for(int i=0; i<v.size(); ++i) {
        if((i % 2) == 0) continue; 
            
        v[i] = 0;
        ++a;
    }
}

void modify(vector<int>* v, int* a) {
    for(int i=0; i<v->size(); ++i) {
        if((i % 2) == 0) continue; 
            
        (*v)[i] = 0;
        ++(*a);
    }
}

int main() {
    int m1=0, m2=0;
    vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int> v2(v);
    
    print(v);
    print(&v2);

    modify(v, m1);
    modify(&v2, &m2);

    std::cout << '\n' << m1 << '\n';
    print(v);

    std::cout << '\n' << m2 << '\n';
    print(&v2);

    return 0;
}
