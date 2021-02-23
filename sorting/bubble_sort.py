def bubble_sort(li):
    for j in range(len(li)):
        swap = False
        for i in range(len(li)-j-1):    # did this because the comparison with last elemnt is not required
            if li[i] > li[i+1]:
                li[i], li[i+1] = li[i+1], li[i]
                swap = True
        if not swap:
            return li # if no swap in whole iteration menas the list is sorted
    return li

arr = [2, 3, 4, 1, 4, 6, 3, 9, -1, -7, 10]
print(bubble_sort(arr))