#include<iostream>
#include<vector>
using namespace std;

void hello() {
    cout<<"Hello, world"<<"\n";
}

int fun(int n) {
    cout<<n<<"\n";
    return n;
}

void Print(int v) {
    cout<<"Value is "<<v<<endl;
}

void for_each(vector<int>&v, void(*p)(int)) {
    for(int value: v) {
        p(value);
    }
}
int main() {
    void(*ptr)() = hello;
    // alt way:-> auto ptr = hello;
    ptr();
    cout<<ptr<<endl;

    int(*ptr1)(int) = fun;
    ptr1(10);
    cout<<ptr1<<endl;

    vector<int> v = {1, 2,3, 4 , 5};
    for_each(v, Print);
}