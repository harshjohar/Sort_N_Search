#include<iostream>
#include<vector>
using namespace std;

void for_each(vector<int>&v, void(*p)(int)) {
    for(int value: v) {
        p(value);
    }
}

void fun(vector<int>&v, void(*p)(int)) {
    for(int value: v) {
        p(value);
    }
}
int main() {
    vector<int> v = {1, 2,3, 4 , 5};
    int h=10;
    for_each(v, [](int v) {cout<<"value is: "<<v<<endl;});
    // fun(v, [&](int x) {cout<<"Puthe pnge: "<<h-x<<endl;})
}