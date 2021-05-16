#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back

class custom_stack_array {
    int arr[1000];
    int sz=0;
public:
    void push(int num) {
        if(sz==1000)
        {
            cout<<"Full";
            return;
        }
        arr[sz++]=num;
    }
    int top() {
        if(sz==0) {
            cout<<"stack empty"<<endl;
            return -1;
        }
        return arr[sz-1];
    }
    int size() {
        return sz;
    }
    bool empty() {
        return (sz==0);
    }
    void pop() {
        if(sz==0) {
            cout<<"stack empty"<<endl;
            return;
        }
        sz--;
    }
    void clear() {
        sz=0;
    }
};

class custom_stack_vect {
    vi arr;
    int sz=0;
public:
    void push(int num) {
        arr.push_back(num);
;    }
    int top() {
        if(arr.empty()) return -1;
        return arr.back();
    }
    int size() {
        return arr.size();
    }
    bool empty() {
        return (arr.size()==0);
    }
    void pop() {
        if(arr.empty()) {cout<<"error"<<endl; return;}
        arr.pop_back();
    }
    void clear() {
        arr.clear();
    }
};

class Node {
 public:
    int data;
    Node *next;

    Node(int d) {
        data=d;
        next=NULL;
    }
};

class custom_stack_LL {
    Node *head;
    int sz;

public:
    custom_stack_LL() {head=NULL; sz=0;}

    void push(int num) {
        Node *new_node = new Node(num);
        new_node->next= head;
        head=new_node;
        sz++;
    }

    int top() {
        if(sz) return head->data;
        cout<<"Stack empty"<<endl;
        return -1;
    }

    void pop() {
        if(!sz) {
            cout<<"Stack Empty\n";
            return;
        }
        Node *new_node = head->next;
        delete head;
        head=new_node;
        sz--;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return (sz==0);
    }

    void clear() {
        while(sz) {
            pop();
        }
    }
};

// Check whether the bracket sequence is correct or not
bool bracket(string s) {
    stack<string> st;
    for(int i=0; i<s.size(); i++) {
        if (s[i]==')') {
            if(st.empty()) return false;
            st.pop();
        }
        else {
            st.push("(");
        }
    }
    if(st.size()) return false;
    return true;
}

// Find min/max of stack in O(1)
class max_min_stack {
    stack<int> s, mn, mx;
public:
    void push(int num) {
        s.push(num);
        mn.empty() ? mn.push(num): mn.push(std::min(num, mn.top()));   
        mx.empty() ? mx.push(num): mx.push(std::max(num, mx.top()));   
    }
    void pop() {
        s.pop(), mn.pop(), mx.pop();
    }
    int top() {
        return s.top();
    }
    int max() {
        return mx.top();
    }
    int min() {
        return mn.top();
    }
};

// There is a road, in T shape. Sequence of cars is given. -> Random
// Output sequence should be in increasing order
// Cars can wait in T section.
// Tell whether this is possible to do so.
bool cars_at_T_point(int* arr) {
    int n; cin>>n;
    stack<int> s1, s2;
    // s1-> main road
    // s2-> service road
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        s1.push(x);
    }
    int car=1;
    while(car<=n) {
        if(s1.size() && s1.top()==car) 
            s1.pop(), car++;
        else if(s2.size() && s2.top()==car)
            s2.pop(), car++;
        else if(s1.size())
            s2.push(s1.top()), s1.pop();
        else {
            cout<<"Not Possible\n";
            return 0;
        }
    }
    cout<<"Possible\n";
}

int main() {
    custom_stack_LL st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    st.pop();
    st.push(56);

    while(!st.empty()) {
        cout<<st.top()<<endl;
        st.pop();
    }
    string s="()()()()()()()()()";
    // cin>>s;
    cout<<bracket(s)<<endl;
}