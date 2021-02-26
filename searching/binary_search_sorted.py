def binary_search(arr, target):
    # when the list if already sorted
    n = len(arr)
    left, right = 0, n-1
    while left <= right:
        # mid = (left+right)//2 (may overflow)
        mid = left + (right-left)//2
        if arr[mid] == target:
            return mid
        elif arr[mid] > target:
            right = mid-1
        else:
            left = mid+1
    return -1

li = [1, 2, 3, 4, 5, 6, 7, 8, 9]
target = 5
print(binary_search(li, target))