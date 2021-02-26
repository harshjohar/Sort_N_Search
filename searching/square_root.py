# Given a perfect square value s, between 1 - 10^9 find its square root
def sq_root(s):
    left = 0
    right = s-1
    while left <= right:
        mid = left+(right-left)//2
        if mid*mid == s:
            return mid
        elif mid*mid > s:
            right = mid-1
        elif mid*mid < s:
            left = mid+1

def floor_sq_root(s):
    if s==1:
        return 1
    left = 0
    right = s-1
    ans = s
    while left <= right:
        mid = left+(right-left)//2
        if mid*mid == s:
            return mid
        elif mid*mid > s:
            right = mid-1
            
        elif mid*mid < s:
            left = mid+1
            ans = mid
    return ans
print(sq_root(4096))
print(floor_sq_root(37))