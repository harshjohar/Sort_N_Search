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
