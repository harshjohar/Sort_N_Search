#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define int long long int

// 2D vector -> vector<vector<int>> v;
// other way -> vector<vector<int>> v(n,vector<int>(m))
// vector<int> has by default value of 0


// Q1
// Given an array of integers(size N)
// Print N numbers where ans[i] = max(a[j]) where j!=i
// Input -> 5 1 2 3
// Output -> 3 5 5 5
void Q1() {
    int n; cin>>n;
    vi a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    int max=a[0];
    int secondMax = a[1];
    for(int i=0; i<n; i++) {
        if(a[i]>max) max=a[i];
        if(a[i]<max && a[i]>secondMax) secondMax=a[i];
    }
    for(int i=0; i<n; i++) {
        if(a[i]!=max) cout<<max<<" ";
        else cout<<secondMax<<" ";
    }
}


// Q2
// Given an array of integers(size N)
// Print N numbers where ans[i] = product(a[j]) where j!=i
// Input -> 5 1 2 3
// Output -> 6 30 15 10
// No element should be 0

void Q2() {
    int n; cin>>n;
    vi a(n);
    int flag = 1;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    } 
    vi prefix(n, 1);
    vi suffix(n, 1);
    prefix[0] = a[0];
    for(int i=1; i<n; i++) {
        prefix[i] = prefix[i-1]*a[i]; 
    }
    suffix[n-1] = a[n-1];
    for(int i=n-2; i>=0; i--) {
        suffix[i] = suffix[i+1]*a[i];
    }
    for(int i=0; i<n-1; i++) {
        cout<<suffix[i+1]*prefix[i]/a[i]<<" ";
    }
    cout<<prefix[n-1]/a[n-1]<<endl;
}

/* ---------------------------------------------------------- */
// Concept
// Prefix / Suffix

// Example
// prefix_max[i] = max(a[0], a[1],....a[i])
// suffix_max[i] = max(a[i], a[i+1], a[i+2], ... a[n-1])

// prefix_sum[i] = sum(a[0], a[1],....a[i])
// suffix_sum[i] = sum(a[i], a[i+1], a[i+2], ... a[n-1])
/* ---------------------------------------------------------- */


// Q3
// Given an array with integers
// Queries: 
//      l r x
//      a[l]+=x, a[l+1]+=x, ..... a[r]+=x
// retrieve the final array
// Input -> 1 2 1 5 6 -3 (1 based indexing)
// 5 5 1
// 1 6 -2
// 3 4 2
// Output -> -1 0 5 5 -5

// Intuition:
// let b = 0 0 0 0 0 0 0 (size n)
// +x at l and -x at r+1 for every query
// now prefix sum
int Q3() {
    int n; cin>>n;
    vi a(n+1);
    for(int i=0; i<=n; ++i) {
        cin>>a[i];
    }
    vi b(n+2);
    int q; cin>>q;
    while(q--) {
        int l, r, x; cin>>l>>r>>x;
        b[l]+=x, b[r+1] = -x;
    }
    for(int i=0; i<=n; ++i)
        b[i] += b[i-1];
    for(int i=1; i<=n; ++i)
        cout<<a[i]+b[i]<<" ";
    return 0;
}

// Q4
// 2D vector
// Queries
// i1, j1 to i2, j2 submatrix 
// Give sum of that submatrix

void Q4() {
    return;
}


// Q5
// http://codeforces.com/contest/1272/problem/C

// Solution:
int Q5() {
    int n, k; cin>>n>>k;
    string s; cin>>s;

    vi ok(26);

    while(k--) {
        char ch; cin>>ch;
        ok[ch-'a'] = 1;
    }

    vi v;
    v.push_back(-1);
    for(int i=0; i<n; i++) 
        if(!ok[s[i]-'a'])
            v.push_back(i);

    v.push_back(n);
    int ans = 0;

    for(int i=0; i+1<v.size(); ++i) {
        int c = v[i+1]-v[i]-1;
        ans+=(c*(c+1))/2;
    }
    cout<<ans<<'\n';
    return 0;
}

// Q6
// Given an array divide the array into maximum number of contiguous parts 
// such that if we sort the individual parts the array also get's sorted

int Q6() {
    return 0;
}


int32_t main() {
    Q1();
    Q2();
    Q3();
    Q4();
    Q5();
    Q6();
    return 0;
}