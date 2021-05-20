# Searching

    It invloves some set of elements, and a target you want to search.

## Linear Search

    Consider you have a list of numbers, and you have to search for a target number.
    > Iterate one by one on all elements, if the current element is equal to the target, return the target.
    
    >> Search space: 
        Region where you have possibilty of finding target.
        'n' for this algorithm

    __Properties__
    >> Time Complexity:     O(n)
    >> Space Complexity:    O(1)

## Binary Search

    Dividing list into half every time, and moving in the direction where the chance of element is there.

    > Data should be arranged in a SPECIFIC MANNER.

    Binary search can be applied on all those search conditions where we can divide the search space into two parts, such that the two parts are distinguishable, based on some property.

    __Properties__
    >> Time Complexity:     O(log(n))
    >> Space Complexity:    O(1)

### Binary Search (Fully Sorted)

    >> implemented in **binary_search_sorted.py**

### Binary Search (Sorted Rotated)

    >> implemented in **binary_search_rotated_sorted.py**

### Binary Search (unsorted)

### Optimization of Insertion Sort
    >> We can try to optimise the insertion by using binary search to find the correct index for inserting.
    >> But ultimately, it doesn't make a difference as the time complexity of insertion sort(O(n**2)) is coming from swaps
    >> Hence time complexity will still be O(n^2)
    >> Thus, no need of binary search there.

### Binary search on Answer
    >> When a function if monotonic, we can apply binary search there.