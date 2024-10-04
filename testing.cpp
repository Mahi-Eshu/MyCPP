#include <iostream>
#include <vector>
using namespace std;

void multiply(int& n){
    n *= 2;
}

int main(){
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);

    for_each(s.begin(), s.end(), [](int& n){
        multiply(n);
    });

    for(int i : s){
        cout << i << " ";
    }
}