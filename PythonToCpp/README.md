# Shift from Python to C++

## Fundamental Differences between py and cpp
+ Python is interpreted, C++ is compiled
+ Python has platform independency, C++ is not.
+ Python code -> intermediate form(python byte code) -> For python vitual machine-> Execution file -> interpreted.
+ C++ code -> Compilation -> Execution file -> Run
+ Python is dynamically typed, C++ is statically typed.

## HelloWorld File
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

## operators
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