import random

def partition(li, left, right):
    # You are given a list of size N, ans an element from the list called as'pivot element'.
    # You need to segeregate all the elements lesser than pivot on the left side & greater than pivot on the right side in any order.    m = left
    m = left
    pivot_index = random.randrange(left, right)
    pivot = li[pivot_index]
    li[right], li[pivot_index] = li[pivot_index], li[right]
    for i in range(left, right):
        if li[i] <= pivot:
            li[i], li[m] = li[m], li[i]
            m+=1
    li[right], li[m] = li[m], li[right]
    return m

def quick_sort(li, left, right):
    if left>=right:
        return
    pivot_index = partition(li, left, right)
    quick_sort(li, left, pivot_index-1)
    quick_sort(li, pivot_index+1, right)

    return
li = [2, 3, 4, 1, 4, 6, 3, 9, -1, -7, 10]
quick_sort(li, 0, len(li)-1)
print(li)