#include<bits/stdc++.h>
using namespace std;

class Tes {
public:
    int x;
    int getX() const{ // -> when function is const, u can't change the value of data members.
        return x;
    }

    void setX(int x) {
        this->x = x;
    }
};

int main() {
    return 0;
}