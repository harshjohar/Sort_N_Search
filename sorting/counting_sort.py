def counting_sort(arr):
    # extracting the max element
    max_element = max(arr)

    # frequency list
    frequency = [0]*(max_element + 1)
    for i in range(len(arr)):
        frequency[arr[i]] += 1
    
    # prefix sum
    for i in range(1, len(frequency)):
        frequency[i] += frequency[i-1]

    output = [0]*len(arr)

    for i in range(len(arr)-1, -1, -1):
        output[frequency[arr[i]] - 1] = arr[i]
        frequency[arr[i]] -= 1
    
    return output

arr = [2, 3, 4, 1, 4, 6, 3, 9, 1, 7, 10]
print(counting_sort(arr))