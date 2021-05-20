#include<iostream>
using namespace std;

int main() {
    // integer
    int *ptr = new int(4);
    cout<<*ptr<<endl;

    // array of int
    int *ptr_arr = new int[13];

    // fixed value 0 at all element in arr
    int *fixed = new int[13]();
    for(int i=0; i<13; i++) 
        cout<<fixed[i]<<" ";
    cout<<"\n";

    // 2D array
    // in stack -> row major and column major
    // in heap -> diff arrays are created at diff addresses whcih stores data. (secondry arrays)
    // another 1D array stores the addresses of the secondary arrays.
    // new -> address of primary array is returned.
    int rows = 13, cols = 12;
    int **grid= new int*[rows]; // -> primary array initiated
    for(int i=0; i<rows; i++)
        grid[i] = new int[cols]; // -> secondary array initiated

    // 2d arrays with diff size cols
    int **grid1= new int*[rows]; // -> primary array initiated
    for(int i=0; i<rows; i++){
        if(i==0) 
            grid1[i] = new int[5]();
        else
            grid1[i] = new int[cols](); // -> seconsary array initiated
    }

    // printing
    cout<<"\n";
    for(int i=0; i<rows; i++) {
        for(int j=0; j< ((i==0) ? 5: cols); j++) {
            cout<<grid1[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;

    // avoiding std::bad-alloc
    int *noth = new (nothrow) int(10);
}