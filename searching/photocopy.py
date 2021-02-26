# you have a practical, you wnet to photocopy shop to bring 'n' copies, there are two machines at the shop
# first one copies a sheet in x seconds, second one copies in y seconds.
# you can run both machines parallely, and can create photocopy of both original and copied page.
# find the minimum time required to make n copies

def good(mid, n, x, y):
    return (mid//x)+(mid//y) >= n


def photocopy(n, x, y):
    if n == 1:
        return min(x, y)
    lo = 0
    hi = max(x, y)*n    #worst case
    ans = -1
    while lo < hi:
        mid = lo + (hi-lo)//2
        if good(mid, n-1, x, y):
            ans = mid
            hi = mid-1
        else:
            lo = mid+1
    return ans + min(x, y)

print(photocopy(5, 1, 2))