def insertion_sort(li):
    for i in range(1, len(li)):
        key = li[i]
        j = i-1
        while j>=0 and key<li[j]:
            li[j+1] = li[j]
            j-=1
        li[j+1] = key
    return li

arr = [2, 3, 4, 1, 4, 6, 3, 9, -1, -7, 10]
print(insertion_sort(arr))