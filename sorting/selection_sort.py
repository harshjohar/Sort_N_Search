def find_min_index(arr, start):
    min = start
    start += 1

    while start< len(arr):
        if arr[start] < arr[min]:
            min = start

        start+=1
    return min


def selection_sort(arr):
    i=0
    while i<len(arr):
        min = find_min_index(arr, i)
        if i != min:
            arr[i], arr[min] = arr[min], arr[i]
        
        i+=1
    return arr

arr = [2, 3, 4, 1, 4, 6, 3, 9, -1, -7, 10]
print(selection_sort(arr))