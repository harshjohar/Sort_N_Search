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


### Vectors