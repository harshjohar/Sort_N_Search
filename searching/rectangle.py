# n rectangle of same size(w x h), it is required to find the square of smallest size into which these rectangles can be packed.
# they cant be rotated
def good(n, mid, h, w):
    return (mid//w)*(mid//h) >= n

def rec_in_sq(h, w, n):
    lo = 0
    hi = max(w, h)*n

    while lo<hi:
        mid = lo + (hi-lo)//2
        if good(n, mid, h, w):
            hi = mid
            ans = mid
        else:
            lo = mid+1
    return ans

print(rec_in_sq(2, 3, 3))