#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define pii pair<int, int>
#define f first
#define s second
#define int long long int
#define endl "\n"

// 2D vector
// Queries
// i1, j1 to i2, j2 submatrix 
// Give sum of that submatrix
void sum_of_submatrix() {
    int n, m; cin>>n>>m;
    vector<vi> matrix(n+1, vi(m+1));
    vector<vi> prefix(n+1, vi(m+1));

    for(int i=1; i<=n; i++) { 
        for(int j=1; j<=m; j++) {
            cin>>matrix[i][j];
            prefix[i][j]+=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        }
    }
    int queries; cin>>queries;
    while(queries--) {
        int i1, j1, i2, j2; 
        cin>>i1>>j1>>i2>>j2; // -> 1 based
        cout<<matrix[i2][j2]-matrix[i1-1][j2]-matrix[i2][j2-1]+matrix[i1-1][j1-1]<<endl;
    }
    return;
}


// https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
// Given an array divide the array into maximum number of contiguous parts 
// such that if we sort the individual parts the array also get's sorted
int maxChunksToSorted(vector<int>& arr) {
    if(arr.size()==1) return 1;
    int ans=0, n=arr.size();
    vi prefix(n); vi suffix(n);
    suffix[n-1]=arr[n-1];
    for(int i=n-2; i>=0; i--) 
        suffix[i]=min(arr[i], suffix[i-1]);
    int maxx = arr[0];
    for(int i=0; i<n; i++) {
        if(i==n-1)
            ans++;
        else if(maxx<=arr[i]&&arr[i]<=suffix[i+1])
            ans++;
        else if(maxx<=suffix[i+1] && arr[i]<=suffix[i+1])
            ans++;
        maxx=max(maxx, arr[i]);
    }
    return ans;
}

// KADANE ALGORITHM
// Maximum subarray sum
void kadane() {
    int n; cin>>n;
    vi v(n);
    for(int i=0; i<n; i++) 
        cin>>v[i];
    
    int max_sum=0, curr_sum=0;
    for(int i=0; i<n; i++) {
        curr_sum+=v[i];
        max_sum = max(curr_sum, max_sum);
        curr_sum = max(curr_sum, (int)0);
    }
}

// input a matrix
// Q queries
// Add x to every element in the range (i1, j1) -> (i2, j2)
// print final matrix
void sum_matrix() {
    int n, m; cin>>n>>m;
    vector<vi> v(n+1, vi(m+1));
    for(int i=1; i<=n; i++) 
        for(int j=1; j<=m; j++)
            cin>>v[i][j];
    
    vector<vi> pre(n+2, vi(m+2));
    int q; cin>>q;
    while(q--) {
        int i1, j1, i2, j2, x;
        cin>>i1>>j1>>i2>>j2; //-> 1 based indexing
        pre[i1][j1]+=x;
        pre[i2+1][j1]-=x;
        pre[i1][j2+1]-=x;
        pre[i2+1][j2+1]+=x;
    }

    for(int i=1; i<=n; i++) { 
        for(int j=1; j<=m; j++) {
            pre[i][j]+=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }

    for(int i=1; i<=n; i++) { 
        for(int j=1; j<=m; j++) {
            cout<<v[i][j]+pre[i][j]<<" ";
        }
        cout<<endl;
    }
}

// https://codechef.com/STRG2020/problems/TOTCARS/
void totcars() {  
    string s;
    cin>>s;
    int n = s.size();

    vector<vi> alphabets(100200, vi(26));

    // 2D prefix
    for(int i=0; i<n; i++) {
        alphabets[i][s[i]='a']=1;
    }

    for(int i=1; i<n; i++) {
        for(int j=0; j<26; j++) {
            alphabets[i][j]+=alphabets[i-1][j];
        }
    }

    int q; cin>>q;
    while(q--) {
        int x, y;
        cin>>x>>y; //-> 1 based indexing
        x--; y--;
        vi tmp(26);
        int ans=0;
        for(int i=0; i<26; i++) {
            tmp[i]=alphabets[y][i];
            if(x) 
                tmp[i]-=alphabets[x-1][i];
        }
        for(int i=1; i<26; i+=2) {
            if(tmp[i]) ans++;
        }
        cout<<ans<<endl;
    }
}

// https://spoj.com/problems/BOOKS1
void books() {
    
}
