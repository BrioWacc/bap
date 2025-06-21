#include<iostream>
#include<vector>
#include<utility>

using namespace std;

void foo1(vector<pair<int, int>> ex) {
    for(pair<int, int>& entry : ex) std::cout << entry.first << " " << entry.second << '\n';
}

void foo2(vector<pair<int, int>> ex) {
    for(const auto& entry : ex) std::cout << entry.first << " " << entry.second << '\n';
}

int main() {
    vector<pair<int, int>> ex;

    ex.push_back({3, 20});
    ex.push_back({15, 3});
    
    foo1(ex);
    foo2(ex);

    return 0;
}
