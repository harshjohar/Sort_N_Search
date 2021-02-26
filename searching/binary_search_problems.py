'''
Given a sorted list and an integer x.
Find the first value(index) which is greater than or equal to x
'''
x = 4
li = [1, 2, 3, 6, 7, 8]

# O(n) approach
def linear(li, x):
    ans = -1
    for i in range(len(li)):
        if li[i]>=x:
            ans = i
            return ans

## O(log n)
def binary(li, x):
    ans = -1
    n= len(li)
    lo = 0
    hi = n-1
    while lo <= hi:
        mid = lo + (hi - lo)//2
        if li[mid] >= x:
            ans = mid
            hi = mid - 1
        else:
            lo = mid+1
    return ans

print(linear(li, x))
print(binary(li, x))

'''
Given an unsorted list, 
Find any element a[i] such that a[i]>a[i-1] and a[i]>a[i+1]
There can be multiple answers, find any one.
'''
arr = [1, 2, 3, 4, 5, 8, 4, 6, 4]
# O(n)
def maxima_linear(li):
    for i in range(len(li)):
        if li[i] > li[i-1] and li[i] > li[i+1]:
            return i

# O(log n)

# case 1 is positive slope or when a[i] < a[i+1]
# case 2 is negative slope or when a[i] > a[i+1]

def maxima_optimised(li):
    # mid can hit either a sorted list, or it can hit a reversed sorted list
    lo, hi = 0, len(li)-1
    while lo < hi:
        mid = lo + (hi-lo)//2
        # if mid+1 < len(li) and mid-1 >=0 and li[mid] > li[mid+1] and li[mid]> li[mid-1]:
            # return mid
        
        if li[mid] > li[mid+1]:
            # case 2
            hi = mid
        else:
            # case 1
            lo = mid+1
    return lo
    # in case we are left with only 2 elements then mid will be equal to low or the left element. on a positive slope doing low = mid+1 will ensure the fact that we keep moving towards the peak
    # if you don't do low = mid+1 this it will get stuck in the loop because mid value of low will always be set to mid and
    # high will not change anyway 
    # copy op

print(maxima_linear(arr))
print(maxima_optimised(arr)) 
# both may or maynot give the sam eans, the fact is that this question can have multiple answers and the first one will go from element to element.
# And second one just splits the list into half and then moves towards the peak