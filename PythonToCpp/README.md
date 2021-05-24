# Shift from Python to C++

## Fundamental Differences between Python and C++
+ Python is interpreted, C++ is compiled
+ Python has platform independency, C++ is not.
+ Python code -> intermediate form(python byte code) -> For python vitual machine-> Execution file -> interpreted.
+ C++ code -> Compilation -> Execution file -> Run
+ Python is dynamically typed, C++ is statically typed.

## HelloWorld File
```cpp
#include<iostream>
using namespace std;
int main() {
    cout<<"Hello, World"<<endl;
    return 0;
}
```
+ `#include<iostream>`
    + #include -> preprocessor
    + iostream -> header file
+ `using namespace std;`
    + Certain set of syntax in accordance with std C++.
+ `int main()`
    + Function
    + Execution starts here.
+ `cout`
    + print the data.
+ `return 0`
    + return value of function.

## Basic stuff
+ `sizeof()` : return the size of object(in bytes).
It is machine-dependent. But in most machines nowadays, following are defined sizes.
    + bool : 1
    + int : 4
    + long : 8
    + short : 2
    + char : 1
    + string : 24
+ `signed/unsigned` : takes/drops negative ints
+ `array` : It is linear DS, that stores _homogenous_ elements in _contiguous_ memory location, and is _fixed size_.

## Operators
+ arthimatic
    + +(add)
    + -(subtract)
    + *(multiply)
    + /(divide)
    + %(modulo)
+ boolean
    + and/&&
    + or/||
    + not/!
+ bitwise
    + & (and)
    + | (or)
    + ~ (complement)
    + ^ (xor)
    + (<<) (left shift)
    + (>>) (right shift)
+ assignment
    + += -> x=x+_
    + -= -> x=x-_
    + *= -> x=(x * _)
    + /= -> x=x/_
    + ++ -> x=x+1
    + -- -> x=x-1
+ ternary
    + example
    + `int z = (10<45) ? 100 : 69;`
    + z = 100

## Compiler Optimizations
```cpp
int main() {
    return 0;
}
```
Steps of compilation:
+ raw C++ code
+ expand preprocessors(inlcude, define etc.)
    + `g++ -E <filename>`
+ assembly
    + `g++ -S <filename>`
+ machine excecutable code
    + linkers and loaders -> read more in OS and Microprocessors

There are many levels of optimisation
+ removes unused header files
+ removes unused variables
+ removes unused functions

## Conditionals and Loops
### Conditional
Syntax:
```cpp
if(condition) {
    <some code>;
}
else if(condition 2) {
    <some more code>;
}
else {
    <some more>
}
```

### Loops
+ While loop
    ```cpp
    while(condition) {
        <some code>;
    }
    ```
+ For loop
    ```cpp
    for(initialisation; comparison; increment) {
        <some code>;
    }
    ```

## Custom Practices
### Output Formatting
+ `setw(spaces)` -> to add multiple white spaces
+ `setprecision(size)` -> to set precison after decimal
+ `fixed(x)` -> fixed number of places after decimal.
+ `scientific(x)` -> scientific notation.
+ `cout.precison(x);` -> set the precision for whole file.
+ C style formatting

## Pointers and References
+ Data is stored in the buckets in memory.
+ Address has a hexadecimal value.
+ __Pointer__ : Variable used to store memory addresses.
+ Address is stored with the specific data type.
+ __Syntax__:
    + `<var-type> *<ptr-name> = <address>`;
```cpp
// initialising a pointer
int x=10;
int *ptr = &x;  // ->int pointer
bool b = true;
bool *ptrBool = &b; // -> bool pointer

int**ptr2 = &ptr; // pointer to a pointer, which is a pointer to int.
```
+ _Significance of `*`_:
    + *LHS* : initiate a pointer.
    + *RHS* : Derefernce an address.

+ _Significance of `&`_:
    + *LHS* : Reference operator.
    + *RHS* : Get the address of a variable.

+ __*sizeof(pointer)*__ = 8 bytes
### Pointer arthimetic
Pointer variable supports the following arthimetic operations.
+ ++ 
+ -- 
+ += 
+ -=

Commonly used to in arrays.
+ To move in an array
```cpp
int arr[4] = {1,2,3,4};
// arr -> address to the base pointer(arr[0])
arr = arr+1; // -> now arr points to arr[1]
```
### Dereferencing Operators
+ Extract the value out of address
+ `*` is the dereferencing operator.
```cpp
int x=10;
int *ptr=&x;
cout<<ptr<<endl;
//-> gives address
cout<<*ptr<<endl;
//-> gives 10
```
## References
It is an alternative name for existing variable.
+ When more variables point to the same bucket in memory.
+ When the value is changed at any reference, it is evident at all other references.
```cpp
int x=10;
int &p=x;
p++;
cout<<x<<endl;
//-> gives 11
```

### Pass by value/reference
+ __*Pass by Value/copy*__ : Makes a copy of variable to pass in a function etc.
```cpp
int x=10;
int y=5;
void fun(int x, int y)  {
    int tmp=x;
    x=y;
    y=tmp;
}
fun(x, y);
// -> no change will be observed in real x, y
```
+ __*Pass by Reference/Address*__ : Original variable in passed, any change will be observed in the original variable.
```cpp
int x=10;
int y=5;
void fun(int *x, int *y)  {
    int tmp=*x;
    *x=*y;
    *y=tmp;
}
fun(&x, &y);
// -> change will be observed in real x, y
```
### Important info about references.
+ Once a reference is declared and defined, its value can't be reassigned.
```cpp
int x = 10;
int &f = x;
int y = 9;
f = y;
// -> here value of both x and f will become equal to y, but f will still remain only a reference of x and not of y
```
+ Pointers can be reassigned.
+ References cannot be NULL.
+ References need to be defined when declared.
+ `int &x` is not correct

+ Pointers can be declared without defining.

## Structs in C++
Custom user defined data-types. Amalgam of multiple primitive data types. Only available in here.

Example: A product in e-commerce website(pseudocode).
```
Product {
    string name;
    string description;
    float cost;
}
```

### Implementation in C++
```cpp
struct strname {
    // data members
    string name;
    string descrption;
    int cost;
    int id;

    // member functions
    void display {
        cout<<"Name: "<<name;
        cout<<"Cost: "<<cost;
    }
}; 
```

### Defining in main
```cpp
struct strname str1;
string n = str1.name //-> to get data values
str.display() // -> to run member functions

// initialisation with values
struct strname str2 = {"Iphone", "Bekaar phone", 100900, 38624};
// order should be same.
```

### Passing into a function
By default struct is passed by copy into the functions.
```cpp
void updateStr(strname s, int x) {
    s.cost = x;
    return;
} // -> memory inefficient.
```

Passing by refernce
```cpp
void updateStr(strname &s, int x) {
    s.cost = x;
    return;
} // -> can change the real struct
```
### Advantages of References
Very helpful when we don't want copies of same data in the memory. 

## Types of pointers
1. __Dangling pointer__: A pointer pointing to a memory location that has been deleted. Can create issues in the runtime.
2. __NULL pointer__: A pointer which points to nothing or NULL.
    + NULL and uninitialised ptr are different.
    ```cpp
    // NULL
    int *p1 = NULL;
    // Uninitialised
    int *p2; //-> point to any random address.
    ```
3. __Void Pointer__: Generic Pointer. Can point to anything. We don't need to define the data type of this type of pointer.
    + Can't dereference it.
    + No pointer arthematic is supported.
    ```cpp
    void *ptr;
    ptr = &x;
    // x can be of any data type.
    ```

    + How to deference?
    ```cpp
    // first type-cast into required type
    int *ptr1 = (int*) ptr;
    cout<<*ptr1<<endl;
    ```

    + Normally, we first initialise a variable and then we get the address.
    + But here, we can get a bucket in memory first, and then set some value.
    + If we use `malloc`, `calloc`, `realloc`.
    ```cpp
    int *pm;
    void *v;
    v = malloc(5); // can be of any size.
    ```
4. __Wild pointer__: An uninitialised pointer is a wild pointer. May lead to memory leakage. `int*p`
5. __Function Pointer__: Advanced C++ L1.

## New and Delete
+ `malloc`, `calloc`, `realloc` are the old function.
+ `new` is a new keyword in C++, it has same use as previous
+ `delete` has same use as `free`.
```cpp
int *p = new int
*p = 10;
cout<<p<<" "<<*p<<endl;
```
### Arrays
Covered in L1 Advanced concepts in C++.
```cpp
// methods to initiate an array in heap
int *a = new int[10];

// 2D array
int* *arr = new int *[10]; 
for(int i=0; i<10; i++) {
    arr[i]=new int[10];
}
// array in stack frame
int arr[10];
```

### delete
```cpp
delete x; // for int
delete [] x; // for array
```
2d array
```cpp
for(int i=0; i<n; i++) {
    delete [] arr[i];
}
delete [] arr;
```

### nothrow
It will stop the error even if the memory if full in runtime. Otherwise it gives a bad-alloc error.
```cpp
int *d = new(nothrow) int(9);
```

## Now play with pointers and references
BYE BYE