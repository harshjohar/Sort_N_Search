# bisect : python library to use binary search

# bisect left : find the leftmost possible index to insert in the list such that list is still sorted.
# bisect right : find the rightmost possible index to insert in the list such that list is still sorted.

import bisect
li = list(map(int, input().split()))

while True:
    ch = input()
    if ch == 'l':
        x = int(input())
        print(bisect.bisect_left(li, x))
    elif ch == 'r':
        x = int(input())
        print(bisect.bisect_right(li, x))
    else:
        print('akal nu hath maar')