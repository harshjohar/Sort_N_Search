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

## Lecture 2
### Pending

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
References cannot be NULL.
References need to be declared when defined.
+ `int &x` is not correct

Pointers can be declared without  defining.