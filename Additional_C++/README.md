# Additional Concepts in C++

## Memory Management
### Pointers
+ Variable that stores address.
+ When a variable in initialized, it is stored in a stack frame.
+ ```int* ptr = &x;```
+ If we want to access the variable even after removing the stack frame: 
    + in C, malloc is used
    + We use heap to solve this problem.
    + A bucket is made in heap part of memory, and pointer to it is used in stack frame.

### new and delete
+ __new__ : replacement of malloc, calloc
    + It initialise a bucket in heap, and return its pointer to the function.
    + Syntax: 
        + ```<data-type>* <variable-name> = new <data-type>(value);```
+ __delete__: replacement of free in C++

### Function Pointers
+ Address which stores the function
+ Syntax:
    + ```<return_type>(*<variable_name>)(<argument_type>) = <function_name>```
    + ```auto <variable_name> = <function_name>```
+ Used to pass a function are a parameter to other function.

### Lambda's in C++
+ Similar to lambda in python
+ [] -> use external variables in lambda
+ Used to declare and use a function in same line.
+ Syntax(example):
    + ```[](int v) {cout<<"value is: "<<v<<endl;}```

### Smart pointers
+ Only way to store values in heap, pointers must be used. And they need to be removed manually.
+ __*Smart Pointers*__ is a solution to this problem, deleting up the memory space will be automatically managed by them.

### Three types of smart pointers
+ Unique
+ Shared
+ Weak

__Unique Pointer__: If we have created an object using unique pointer, no other pointer can point to this object.

__Shared Pointer__: It gives you access to share object.

__Weak Pointer__: It does not keep a refernce count.  It does not give access to use the object. It is just for inspection purpose. Solve the prob of dangling pointer.
It can help in checking whether the pointer is deleted, using `expired()` method.

Smart pointer keep a *reference count*. This helps in the implementation of diff smart pointer. 


### Destructure
Function executed just before a struct gets removed from memory.


## Object Oriented Programming(OOPs)
### Objects
Real life enities, also called instances.
### Class
Blue print of a real life object.

Increase readability of the code.
Given a huge upper hand in using business logic.

### Object
+ Each object has data members and functionalities.

### Constructor
It creates a new instance(object) of a class.

### Visibility
+ __*Private*__ : Default. Not visible anywhere outside the class.
+ __*Public*__ : Accessible everywhere.
+ __*Protected*__

### What happend when we create an object?
First it will store the data members.

### "this" pointer
This store the address of the object in memory.

### -> and . notation
+ If accessing via a _pointer_, use ->
+ If accessing via an _object_, use .

### Structs and Classes
Only difference between struct and class in C++ is that, everything in struct in public by default but we can have custom visibility modifier in classes.

Structs also support private and protected.
__Class__ is widely used in industry.

### const keyword
The variable which cant be reassigned.
> Promises are made to be broken -- Sanket Singh, 2021
```cpp
const int x = 24;
x = 26; // -> not allowed

int *ptr = &x; // -> give error
const int *ptr = &x; // -> we cant change value

const int *p = &x;

int *ptr = new int;
*ptr = 2;
ptr = (int) &x;
// p and ptr have same value

cout<<x<<" "<<*ptr<<endl; // -> x not changes, *ptr shows changed result.
// -> very wierd.
```

+ const int*
+ int const*
    + We cant change the value, but cant change the value.

Above two are same
+ int* const
    + Change the value, no reassignment

```cpp
const int *a = new int; // -> never change value
c = (int*) &x;

int* const a = new int; // -> no reassignment, but change of value permitted


const int *p const z = 420;   // -> compeletely blocked pointer.
```
If a fucntion has const parameters, then any non-const function can't be used inside that fucntion.

+ Use `mutable` keyword to bypass const
```cpp
mutable int x = 45; // this can be changed in const functions.
```

### Costructors
+ If we write no costructor, compiler uses the deafult.
+ Otherwise it will not use default.

+ There are many ways to "construct" an object
```cpp
class ComplexNumber {
    int real, img;

    ComplexNumber() {} //-> random value int

    ComplexNumber() {
        this->real=0;
        this->img=0;
    }

    ComplexNumber() : real(0), img(0){}
    ComplexNumber(int real, int img) {
        this->real=real;
        this->img=img;
    }
};
```

__Constructor overloading__ : 
+ Solved in compile time.

### Polymorphism
Poly -> Many, morphism -> form
Two types
+ Compile time (early binding, static binding)
+ Run time 
### Overloading and Overriding
### Operator and Function Overloading