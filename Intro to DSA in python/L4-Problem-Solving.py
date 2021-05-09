# https://codechef.com/problems/AVGSORT
def avgsort():
    for _ in range(int(input())):
        n=int(input())
        arr=list(map(int, input().split()))
        flag = False
        for i in range(n-1):
            if arr[i]<arr[i+1]:
                flag=True
        if flag:
            print("Yes")
        else:
            print("No")
    return

'''
Given an array of n integers, find no. of sub arrays such that sum of elements of the subarray is k.
'''
def sub_seq_array_sum(arr, k):
    n=len(arr)
    l, r = 0, 0
    sum_=0
    res = 0
    while r<n:
        sum_+=arr[r]
        while l<n and sum_ > k:
            sum_ -= arr[l]
            l+=1
        res += (r-l+1)
        r+=1
    return res


# https://codeforces.com/problemset/problem/676/C
def substring_equal_letters(arr, k):
    s, sum_, ans=0
    for i in range(n):
        if arr[i]=='b':
            sum_+=1
        while sum_>k:
            s+=1
            if arr[s]=='b':
                sum_-=1
        ans = max(ans, i-s+1)
    s=0
    sum=0
    for i in range(n):
        if arr[i] == 'a':
            sum_+=1
        while sum_>k:
            s+=1
            if arr[s]=='a':
                sum-=1
        ans = max(ans, i-s+1)
    print(ans)