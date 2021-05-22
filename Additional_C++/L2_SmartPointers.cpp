#include<bits/stdc++.h>
using namespace std;
struct Players
{
    int x, y;
    void display() {
        cout<<x<<" "<<y<<endl;
    }
    ~Players() {
        cout<<"Player died"<<endl;
    }
};
int main() {
    unique_ptr<Players> ptr1 = make_unique<Players>();
    // -> destructor is called automatically.
    // cout<<ptr1.use_count()<<endl; -> no need of use_count in unique.
    // if we use new, it should be destructed manually.
    // -> above code is same as
    Players* ptr2 = new Players;

    ptr1->x = 1;
    ptr1->y = 1;
    ptr1->display();

    // shared pointer
    shared_ptr<Players> ptr3 = make_shared<Players>();
    shared_ptr<Players> ptr4 = ptr3;
    cout<<ptr3.use_count()<<endl;

    // weak pointer
    weak_ptr<Players> ptr5(ptr3);
    cout<<"hello"<<endl;
    cout<<ptr5.use_count()<<endl;
    cout<<ptr5.expired()<<endl;

    // make real life variables
    unique_ptr<int> ptr6 = make_unique<int>(); // pointer to int
    unique_ptr<int[]> ptr7 (new int[9]); // -> pointer to int array
    return 0;
}