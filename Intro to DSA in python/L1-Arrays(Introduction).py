import array as arr

# first argument is type
# i - integer
# d - decimal
x = arr.array('i', [1,2,3,4,5])
print(x) # prints the object as in it
print(type(x))

# for individual elements
for element in x:
    print(element)

# Given a list of n size and a non negative number k, rotate list by k steps
def reverse(li, s, e):
    while s<e:
        tmp=li[s]
        li[s]=li[e]
        li[e]=tmp
        s+=1
        e-=1
def rotate_array(arr, k):
    n=len(arr)
    k=k%n
    reverse(arr, 0, n-1)
    reverse(arr, 0, k-1)
    reverse(arr, k, n-1)
    return arr

print(rotate_array([1,2,3,4,5,6,7], 3))