#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define pii pair<int, int>
#define f first
#define s second
#define int long long int
#define endl "\n"


// given an array consisting of unique values, Find the total sum of maximum value of all sub arrays.
vi get_pge(vi arr, int n) {
    vi ans(n);
    stack<int> s;

    for(int i=0; i<n; i++) {
        while(s.size() and arr[s.top()] <= arr[i])
            s.pop();
        ans[i]=s.empty() ? -1 : s.top();
        s.push(i);
    }
    return ans;
}

vi get_nge(vi arr, int n) {
    vi ans(n);
    stack<int> s;

    for(int i=n-1; i>=0; i--) {
        while(s.size() and arr[s.top()] <= arr[i])
            s.pop();
        ans[i]=s.empty() ? n : s.top();
        s.push(i);
    }
    return ans;
}

void solve1() {
    int n; cin>>n;
    vi arr(n);

    for(int &i : arr) cin>>i;

    vi nge = get_nge(arr, n);
    vi pge = get_pge(arr, n);

    int ans=0;

    for(int i=0; i<n; i++) {
        ans+=(i-pge[i])*(nge[i]-i);
    }

    cout<<ans<<endl;
}


// given two arrays X and P (X is sorted).
// Find a pair of distinct integers i, j such that abs(x[j]-x[i]) + P[i] + P[j] is maximum

pii getAns(vi x, vi p, int n) {
    int max_diff = p[0]-x[0], max_id=0, max_ans = INT_MIN;
    pii ans = {-1, -1};

    for(int j=1; j<n; j++) {
        int cur_sum = p[j]+x[j];

        if(cur_sum + max_diff > max_ans)
            max_ans = cur_sum + max_diff, ans = {max_id, j};

        if(p[j]-x[j] > max_diff) 
            max_diff = p[j] - x[j], max_id = j;
    }
    return ans;
}

void solve2() {
    int n; cin>>n;
    vi x(n), p(n);

    for(int &i : x) cin>>i;

    for(int &j : p) cin>>j;

    pii ans = getAns(x, p, n);
    cout<<ans.f<<" "<<ans.s<<endl;
}


// condition:
// that abs(x[j] - x[i]) <= k (given)

// for any j
    // max(p[i] - p[j]) where i<j and x[j] - x[i] <=k

pii getAns2(vi x, vi p, int n, int k) {
    pii ans = {-1, -1};
    deque<int> q;
    int max_ans = INT_MIN;

    for(int j=0; j<n; j++) {
        while(q.size() and x[j] - x[q.front()] > k) 
            q.pop_front();

        if(q.size()) {
            int id = q.front();
            int cur_sum = p[j]+x[j];

            if(cur_sum + p[id] - x[id] > max_ans) 
                max_ans = cur_sum+p[id]+x[id], ans={id, j};
        }

        while(q.size() and p[q.back()] - x[q.back()] <= p[j]-x[j]) 
            q.pop_back();
        
        q.push_back(j);
    }
    return ans;
}

void solve3() {
    int n; cin>>n;
    int k; cin>>k;
    vi x(n), p(n);

    for(int &i : x) cin>>i;

    for(int &j : p) cin>>j;

    pii ans = getAns2(x, p, n, k);
    cout<<ans.f<<" "<<ans.s<<endl;
}


// x[i] is angle in degrees
// d=abs(x[i]-x[j])
// maximize(min(d, 360-d) + p[i] + p[j])
pii getAns3(vi x, vi p, int n) {
    pii ans1 = getAns2(x, p, n, 180);

    pii ans2 = {1, 1};

    int max_sum = 0, max_id=-1, i=-1, max_ans = INT_MIN;

    for(int j=1; j<n; j++) {
        while(i+1<j and x[j] - x[i+1] > 180) {
            if(x[i+1] + p[i+1] > max_sum) {
                max_sum = x[i+1] + p[i+1], max_id = i;
            }
            i++;
        } 

        int cur_diff = p[j] - x[j];

        if(max_id !=-1 and cur_diff + max_sum > max_ans) 
            max_ans = cur_diff + max_sum, ans2 = {max_id, j};
    } 

    int i= ans1.first, j=ans1.second;


    if(i==1 and max_ans > abs(x[i]-x[j])+p[i]+p[j])
        return ans2;

    return ans1;
}



// many buildings in a row, bahut door door
// how many building can he see on right

// calculate nge of all elements
// my ans = nge of my nge+ so on

int32_t main() {
    return 0;
}