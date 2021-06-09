#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define mii map<int, int>
#define pi pair<int, int>

// given an array of integers and a number k, Find the max of each sub array of size k.

// map method O(nlogn)


// queue method O(n)
void max_sub_array(vi v, int k) {
    
    int n=v.size();
    deque<int> q;
    for(int i=0; i<k; i++) {
        while(q.size() and v[q.back()]<=v[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    cout<<v[q.front()]<<' ';

    for(int i=k; i<n; i++) {
        if(q.front()==i-k) {
            q.pop_front();
        }
        while(q.size() and v[q.back()]<=v[i]) {
            q.pop_back();
        }
        q.push_back(i);

        cout<<v[q.front()]<<' ';
    }
}


// N people, given a list of pairs of friends.
// We're hosting a party and a person can come to the party only if atleast k of his friends have come. 
// Tell the maximum no. of people that we can expect in the party.

// create an adjacency list
void party() {
    int n, m, k;
    cin>>n>>m>>k;
    vector<vi> adj(n+1);
    vi num(n+1);
    vector<bool> coming(n+1, true);


    while(m--) {
        int i, j;
        cin>>i>>j;
        adj[i].push_back(j);
        adj[j].push_back(i);

        num[i]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++) 
        if(num[i]<k) 
            coming[i]=false, q.push(i);

    while(!q.empty()) {
        int i=q.front();
        q.pop();

        for(int j : adj[i]) {
            num[j]--;

            if(num[j] == k-1) 
                coming[j]=false, q.push(j);
        }
    }

    for(int i=1; i<=n; i++)
        if(coming[i])
            cout<< i <<" ";
    cout<<endl;
}