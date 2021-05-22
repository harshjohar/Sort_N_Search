#include<bits/stdc++.h>
using namespace std;

class Product {
public: //-> visibility
    // data memebers.
    string name;
    int cost;
    int discount=0;
    // if these are private, then u cant access them outside the class, however they can be used in public functions.

    // Constructor
    Product(string s, int c) {
        name = s;
        cost = c;
    }

    Product(string s, int c, int d) {
        name = s;
        cost = c;
        discount = d;
    }
    // Functionalities
    void display() {
        cout<<name<<" "<<cost<<" "<<discount<<endl;
    }

    void set_cost(int c) {
        cost = c;
    }

    Product *pointer() {
        return this;
    }
private:
    void CatchMeIfYouCan() {
        cout<<"I will no get used anywhere outside the class."<<endl;
    }
};

int main() {
    Product Iphone("XR", 69420);
    Iphone.display();
    Product shirt("red", 437, 20);
    // shirt.name = "blue men's shirt";
    // shirt.cost = 69;
    shirt.display();
    shirt.set_cost(234);
    shirt.display();
    Product*p = shirt.pointer();
    Product *pi = &Iphone;
    cout<<pi->cost<<endl;   // ->
    cout<<(*pi).cost<<endl; // .
    cout<<p<<endl;
}