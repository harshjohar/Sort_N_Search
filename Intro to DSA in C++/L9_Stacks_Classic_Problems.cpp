#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
// solve an expression
// In-fix expression -> simple way like 2+3*7-8/3
// need to change it to post-fix expression
int prec(char ch) {
    if(ch=='/' or ch=='*') return 2;
    if(ch=='+' or ch=='-') return 1;
    return -1;
}
string postFix(string s) {
    stack<char> operators;
    string ans;

    for(char ch:s) {
        if(isdigit(ch)) ans+=ch;
        else if(ch=='(') operators.push(ch);
        else if(ch==')') {
            while(operators.top()!='(') 
                ans+=operators.top(), operators.pop();
            operators.pop();
        }
        else {
            while(operators.size() and prec(operators.top())>=prec(ch)) {
                ans+=operators.top(), operators.pop();
            }
            operators.push(ch);
        }
    }

    while(!operators.empty()) 
        ans+=operators.top(), operators.pop();
    cout<<ans<<endl;
    return ans;
} 
void evaluate(stack<int>&s, char ch) {
    int b=s.top();
    s.pop();
    int a = s.top();
    s.pop();

    switch(ch) 
    {
        case '+': 
            s.push(a+b);
            break;
        case '-': 
            s.push(a-b);
            break;
        
        case '*': 
            s.push(a*b);
            break;
        
        case '/': 
            s.push(a/b);
            break;
    }
}
int solve_eqn(string s) {
    stack<int> operands;
    for(char ch : s) {
        if(isdigit(ch)) 
            operands.push(ch-'0');
        
        else {
            evaluate(operands, ch);
        }
    }
    return operands.top();
}


// stock span problem
void prev_greater() {
    int n; cin>>n;
    vector<int> arr(n), pg(n-1);
    for(int i=0; i<n; i++) cin>>arr[i];
    stack<int> s;
    for(int i=0; i<n; i++) {
        while(!s.empty() and arr[s.top()] <=arr[i]) {
            s.pop();
        } 
        s.empty() ? pg[i]=-1 : pg[i]=s.top();
        s.push(i);
    }
    for(int i=0; i<n; i++) {
        cout<<i-pg[i]<<' ';
    }
    cout<<"\n";
}

// next greater -> same implementation + reverse for loop
void next_greater() {
    int n; cin>>n;
    vector<int> arr(n), ng(n-1);
    for(int i=0; i<n; i++) cin>>arr[i];
    stack<int> s;
    for(int i=n-1; i>=0; i--) {
        while(!s.empty() and arr[s.top()] <=arr[i]) {
            s.pop();
        } 
        ng[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    for(int i=0; i<n; i++) {
        cout<<ng[i]-i<<' ';
    }
    cout<<"\n";
}


// prev smaller
vi prev_smaller(vi arr) {
    // int n; cin>>n;
    // vector<int> arr(n), ps(n-1);
    // for(int i=0; i<n; i++) cin>>arr[i];
    int n= arr.size();
    stack<int> s;
    vi ps(n-1);
    for(int i=0; i<n; i++) {
        while(!s.empty() and arr[s.top()] >=arr[i]) {
            s.pop();
        } 
        s.empty() ? ps[i]=-1 : ps[i]=s.top();
        s.push(i);
    }
    // for(int i=0; i<n; i++) {
    //     cout<<i-ps[i]<<' ';
    // }
    // cout<<"\n";
    return ps;
}

// next smaller
vi next_smaller(vi arr) {
    // int n; cin>>n;
    // vector<int> arr(n), ns(n-1);
    // for(int i=0; i<n; i++) cin>>arr[i];
    int n=arr.size();
    vi ns(n-1);
    stack<int> s;
    for(int i=n-1; i>=0; i--) {
        while(!s.empty() and arr[s.top()] >=arr[i]) {
            s.pop();
        } 
        ns[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    // for(int i=0; i<n; i++) {
    //     cout<<i-ns[i]<<' ';
    // }
    // cout<<"\n";
    return ns;
}

// given a histrogram, find largest rectangular area
// all bars have same width
int area() {
    int n; cin>>n; 
    vi arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    vi ps = prev_smaller(arr), ns=next_smaller(arr);
    int max_area = 0;
    for(int i=0; i<n; i++) {
        int b=ns[i]-ps[i]-1;
        int l = arr[i];
        max_area = max(l*b, max_area);
    }
    cout<<max_area<<'\n';
    return 0;
}

int main() {
    string s = "4+3*5+(9/3+7)";
    cout<<solve_eqn(postFix(s))<<"\n";
    vi arr;
    arr.push_back(5);
    arr.push_back(4);
    arr.push_back(8);
    arr.push_back(2);
    arr.push_back(1);
    vi ns = prev_smaller(arr);
    for(int i=0; i<4; i++) cout<<ns[i]<<" ";
    // next_greater();
    // prev_greater();
}

// 5 4 8 2 1
//   1 3 3 4