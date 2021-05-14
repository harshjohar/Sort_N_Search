# Basic data structures

## Basic level data structures
### Linear
    >> stacks
    >> queue
    >> Deque
    >> Linked Lists
### Hierached data structures
    >> Trees
    >> Binary trees - Binary search tree

### Hashmaps

### Advanced
    >> Heaps
    >> Tries
___
___
## What is a data structure?
    It is a particular way of storing and organising your data.

***
### Arrays
    Memory Management
    Scoping
    Basic arrays
    Dynamic Arrays - Lists in python
    Problem Solving

#### Memory Management
    How Data is stored in memory?

    2 major partitions
    + Call Stack
        + Linear
        + Follows LI-FO
            Last In First Out
        + In python - This stores function calls only.
        + Whenever we call a function, a stack from enters the call stack
        + When the call ends i.e. we hit return, stack frame is removed.

        + In python a stack frame only stores references to the variable whereas is C++ they actually sometime store the variable values
        + Real values are stored in heap, only reference is passed in call stack.

    + Heap Area
        Big Pool of memory
        No specific orientation
    
    + Minor partitions
        + Space for global variables
        + Kernel stack

#### Garbage Collection
    This is an automatic process, which frees unused memory location.

    CPython
        + It keeps track of all allocated memory.
        + It maintains generation of the memory spot
            + First Gen - newly allocated memory
            + Older Gen - Garabage collector runs on this, to check the unallocated memory and then cleaned.
        + It maintains no. of allocated memory spots & checks if may exceed a threshold, when they exceed, garbage collector is triggered.

    References counting
        + Counts the number of references, when its number changes, GC triggers.
___
___
## Arrays
    Arrays are linear data structure, which stores homogenous data in contigious memory location.
    + Using array module in python
    + For arrays we need to specify the size as they have fixed length always.
    + Arrays are Mutable.

### Lists
    Resizable data structure, containing heterogenous elements stored in continuous memory loss.
    Can be resized at runtime.
    + To increase size - It makes a copy with greater size and delete the old array/list.
    + For optimisation - Size is not increased everytime, it gets doubled when it is filled.

    TC = theta(1) {average}
    Worst case = O(n)

___
___

## Object Oriented Programming
    + Classes
    + Objects

### Terminologies
___

#### Class
    It is a user defined prototype/blueprint for a real world object that defines properties of the object.
    All Functions are written here, called as methods.
#### Object
    This is an individual real world entity that is based on the blueprint of some class. This is a unique instance of a class.
#### Constructor
    Special function which is used to initialise a brand new object from a class.
    
    In python this function is '__init__'
___
___

## Linked Lists
    What is need of linked list?

    Issues with arrays:
        > We need to give size of arrays
        > Always have contiguous memory allocation.
    
    Linked lists are linear data structure that store one data element in ana entity called as a node, and multiple such nodes are connected to form a chained list. The nodes are not required to be created in continuous memry blocks, so linked lists never consumes continuous memory space.

    > Like a necklace, each bead is a node.

    Each node has:
        > Data value
        > Address value of next node.

    Head : First Node
    Tail : Last Node

    Types of linked lists:
        > Singly linked list
    
    Uses:
        > Forward and backward buttons
        > Music players
        > Cache Algorithms
        > Base of Hash-maps

### Linked List Methods
    Insert at head - O(1) - vs O(n) is arrays
    Insert at the tail - O(n) - same as arrays
    Insert at middle - O(n) - same as arrays

### DOubly Linked List
    Insert at head - O(1) - vs O(n) is arrays
    Insert at the tail - O(1) 
    Insert at middle - O(1)

### Types of Linked Lists
    - Singly LL
    - Double LL
    - Circular LL
    - Doubly Circular LL