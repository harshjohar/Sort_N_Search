def merge_two_sorted_lists(a, b):
    # space complexity = O(n+m)
    # time complexity = O(n+m)

    m = len(a)
    n = len(b)

    output = [0]*(m+n)

    i, j, k = 0, 0, 0
    while i<m and j<n:
        if a[i] < b[j]:
            output[k] = a[i]
            i+=1
            k+=1
        else:
            output[k] = b[j]
            j+=1
            k+=1
    while j<n:
        output[k] = b[j]
        j+= 1
        k+=1
    while i<m:
        output[k] = a[i]
        i += 1
        k+=1
    
    return output

'''
RECURSION
BAse case: when length of list is one.
Self work: Merge the left and right part.
REcursive intution: Sort the left half, sort the right half.
'''

def merge_sort(arr, left, right):
    if left == right:
        return [arr[left]]
    mid = (left+right)//2
    left_half = merge_sort(arr, left, mid)
    right_half = merge_sort(arr, mid+1, right)
    
    output = merge_two_sorted_lists(left_half, right_half)
    return output

arr = [2, 3, 4, 1, 4, 6, 3, 9, -1, -7, 10]
print(merge_sort(arr, 0, len(arr)-1))