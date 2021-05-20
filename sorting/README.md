# Sorting

    Arranging a set of elements in a specific/particular order or permutation.

Q: you have a list of integers and you are supposed to sort them in ascending order

    -> input : [2, 1, 0, 3, 6, -1]
    -> output: [-1, 0, 1, 2, 3, 6]

## Brute force

    In order to sort a list based on any creteria, we can try all the permutations of the list and for every permutation, check if it is the desired result or not.

## Sorting is one of the most relevant problems in CS

    Applications:
        -> E commerce
        -> File manager

### Creteria of sorting can be any comparable quantity of the given object

### Sorting any object

    When we prepare our algorithms for sorting many things to keep in mind two things:
        -> Time complexity
        -> Space complexity
        -> No. of comaparisons
        -> No. of swaps
        -> Inplace or Not?
            > Whether same list is updated(Inplace), or a new is made.
        -> Stability of the sorting algorithm

### Comparators

    Example
        -> assume we have a list of dictionaries (Fully explained in [comparators.py])

    Used to compare two complex objects like products, cars, etc. (Which cannot be sorted directly like a list of numbers.)

### Types of sorting algorithms

    1. Comparison based
    2. Couting based

#### Comparison based

    > Bubble Sort
    > Selection Sort
    > Insertion Sort

#### Counting Based

    > Redix Sort
    > Bucket Sort
    > Counting Sort

#### Stability of algorithm

    Stability means the relative ordering of 2 same elements is maintained i.e. if 2 objects are equal according to the parameter of sorting then their relative order is maintained.
    Example:
        -> Input [p3, p1, p2]
        Let's say p1 = p2 (parameter wise)
        -> output1 = [p1, p2, p3]
        -> output2 = [p2, p1, p3]

        {Given that p3 < p1 = p2}

        -> output1 is stable
        -> output2 is not stable
___

## Selection Sort

    It is a comparison based sorting algorithm.

    [5, 2, 6, 7, 2, 1, 0, 3]

    Let's say some part is sorted while some is not.

    Reach the next spot(y) to be handled.
    -> You want to bring the right element at this place. Which will be obviously from the unsorted part.

    > Hence sorted part will expand and unsorted part will shrink.

    > y is always next to the last element of the sorted part i.e. the first element of the unsorted region.

    y -> first element(in first step) 
    From the unsorted part, find the min in the unsorted part and swap with y.

    __Properties__
    >> Time complexity:     O(n^2)
    >> Space complexity:    O(1)
    >> Number of swaps:     O(n)
    >> In-place:            Yes
    >> No. of comparisons:  O(n^2)
    >> Stability:           NOT STABLE

    >> Time complexity in best case:       Omega(n^2)
    >> Time complexity in avg case:        Theta(n^2)
    ** Implemented in ** selection_sort.py **

## Bubble Sort

    It is a comparison based sorting algorithm.
    > After each iteration the biggest element of unsorted region is at its correct position.

    [14, 33, 27, 35, 10]
    
    Each element will act as a bubble.
    Compare two items at a time.
    
    > If left < right then swap them, compare next two.
    > As sson as we hit he last element, start again.
    > Do this until the ist is sorted.

    __Properties__
    >> Time complexity:     O(n^2)
    >> Space complexity:    O(1)
    >> In-place:            YES
    >> No. of comparisons:  O(n^2)
    >> No. of swaps:        O(n^2)
    >> Stability:           STABLE

    >> Time complexity in best case:    Omega(n)
    ** Implemented in ** bubble_sort.py **

## Insertion Sort

    It is a comparison based algorithm.
    Let's say some part is sorted and some is not.

    > Pick the first element from the unsorted part, insert that at the right place in the     sorted part.
    
    [25, 17, 31, 13, 2]

    __Properties__
    >> Time complexity:     O(n^2)
    >> Space complexity:    O(1)
    >> In-place:            YES
    >> No. of comparisons:  O(n^2)
    >> No. of swaps:        O(n^2)
    >> Stability:           STABLE

    >> Time complexity in best case:       Omega(n)
    >> Time complexity in avg case:        Theta(n^2)
    ** Implemented in ** selection_sort.py **

## Counting Sort

    It is a counting based algorithm.

    Approach 1: Make a dictionary type mappings of key value pairs, which stores the key as the elements and values as the frequency. 
        -> This process is Unstable, as the element added to bucket first, will be collected out at last.
    
    Approach 2: 
        > Make two lists, one input list, and second one stores the corresponding frequency of the elements.
        > Take the cumulative sum.
        > The sum represents the position of the last occurance of the element in the sorted list.
    
    __Properties__
    >> Time complexity:     O(n+k)    {k is the list of elements}
    >> Space complexity:    O(n+k)    {k is the list of elements}
    >> In-place:            NO
    >> No. of comparisons:  ZERO
    >> No. of swaps:        ZERO
    >> Stability:           STABLE

    >> Time complexity in best case:       Omega(n)
    >> Time complexity in avg case:        Theta(n^2)

    >>> If the range of elements is high, this algoritm performs very bad in terms of space and  time complexity.
    ** Implemented in ** counting_sort.py **

___

## Super Sorts

## Merge Sort

    It is a comparison based sort.
    One of the most important.

    It comes under 'Divide and Conquer'

    Basic idea: Sort a big list by merging two sorted lists.

    > Let's say we have an unsorted list.
    > Divide your list into two equal halves.
    > sort the left half recursively, sort the right half recursively.
    > KHATAM

    __Properties__
    >> Time complexity:     O(n(logn))
    >> Space complexity:    O(n)
    >> In-place:            NO
    >> No. of comparisons:  nlogn
    >> No. of swaps:        ZERO
    >> Stability:           STABLE

    ** Implemented in ** merge_sort.py **

## Quick Sort

    It is a comparison based sort.
    Also comes under 'Divide and conqour'

    Let's say you have a list, pick any random pivot. Then do partition of list, based on that pivot.
    Recursively apply the same above logic on the left and right part.

    Partition:
        > Less than or equal to pivot on left side.
        > Greater than on right side.
        > All this to be sone in the same list.

    >>> How to select pivot?
        Randomly select a number.
        Concept of SEED i.e. the st
    Considered as a randomised algorithm.

     __Properties__
    >> Time complexity:     O(n**2) Theta(nlogn) Omega(nlogn)
    >> Space complexity:    O(logn)
    >> In-place:            YES
    >> No. of comparisons:  nlogn
    >> No. of swaps:        ZERO
    >> Stability:           NOT STABLE

    ** Implemented in ** quick_sort.py **

## Python inbuilt

    >> Uses something called as ** TIM-SORT **

## other sorts

    >> heap sort
    >> bucket sort
    >> redix sort
