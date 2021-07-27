# codeforces.com/contest/1272/problem/C
# two pointer approach
def keyboard_problem():
    n, k = map(int, input().split())
    s = input()
    binary = []
    available = list(map(str, input().split()))

    for char in s:
        if char in available:
            binary.append(1)
        else:
            binary.append(0)
    ans = 0

    tmpCount=0
    for i in range(n):
        if binary[i]==1:
            tmpCount+=1
        else:
            ans+=(tmpCount*(tmpCount+1)//2)
            # print(tmpCount)
            tmpCount=0
    ans+=(tmpCount*(tmpCount+1)//2)
    return ans


# codechef.com/problems/GOLDTRIP
def gold_trip():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))
        for i in range(1, n):
            arr[i]+=arr[i-1]
        # print(arr)
        q = int(input())
        for i in range(q):
            s,e=map(int, input().split())
            # print(s,e)
            if s!=1:
                print(arr[e-1]-arr[s-2])
            else:
                print(arr[e-1])

# You will get a list of size n, of all zeroes. You will get Q queries & in each query you will get 2 numbers l, r. You need to increment all the element from l to r by 1.
# print the final list after processing all queries

def cumulative_sum():
    n = int(input())
    li = [0]*n
    q = int(input())
    for i in range(q):
        l,r=map(int, input().split())
        li[l]+=1
        if r+1<n:
            li[r+1]-=1
    for i in range(1,n):
        li[i]+=li[i-1]
    print(li)

# print(keyboard_problem())
# gold_trip()
# cumulative_sum()
