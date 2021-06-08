#include<bits/stdc++.h>
using namespace std;

// Queue using a LL
// push = add node at back
// pop = remove node from front

// Queue using array
// circular queue to manage space

class Node {
 public:
    int data;
    Node *next;
    Node *prev;

    Node(int d) {
        data=d;
        next=NULL;
        prev=NULL;
    }
};

class custom_queue_LL {
    Node *head, *tail;
    int sz;

public:
    custom_queue_LL() : head(NULL), sz(0), tail(NULL){}

    void push(int num) {
        Node *new_node = new Node(num);
        if(!sz) 
            head = tail = new_node;
        else
            tail->next = new_node, tail=new_node;
        sz++;
    }

    int front() {
        if(!sz) {
            cout<<" Queue empty\n";
            return -1;
        } 
        return head->data;
    }

    void pop() {
        if(!sz) {
            cout<<"Queue Empty\n";
            return;
        }

        if(sz==1) tail=NULL;

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

class circular_queue_using_arr {
    int *arr, st, en, sz, cap;

public: 
    circular_queue_using_arr(int cap) {
        arr = new int[cap];
        st=0; en=-1; sz=0, this->cap=cap;
    }

    void push(int num) {
        if(sz==cap) {
            cout<<"Queue full, kl ana"<<endl;
            return;
        }

        en=(en+1)%cap;
        arr[en]=num;
        sz++;
    }

    int front() {
        if(sz) 
            return arr[st];
        cout<<"Queue empty"<<endl;
        return -1;
    }

    int back() {
        if(sz) 
            return arr[en];
        cout<<"Queue Empty"<<endl;
        return -1;
    }

    void pop() {
        if(!sz) {
            cout<<"Queue khali!"<<endl;
            return;
        }

        st=(st+1)%cap;
        sz--;
    }

    int size() {return sz;}

    bool empty() {return (sz==0);}

    void clear() {
        while(sz)
            pop();
    }
};

class custom_deque_LL {
    Node *head, *tail;
    int sz;

public:
    custom_deque_LL() : head(NULL), sz(0), tail(NULL){}

    void push_back(int num) {
        Node *new_node = new Node(num);
        if(!sz) 
            head=tail=new_node;
        else{
            tail->next=new_node;
            new_node->prev = tail;
            tail=new_node;
        }
        sz++;
    }

    void pop_back() {
        if(!sz) {
            cout<<"Deque Empty\n";
            return;
        }
        if(sz==1) tail=NULL, head=NULL;

        Node *new_node = tail->prev;
        delete tail;
        tail=new_node;
        sz--;
    }

    void push_front(int num) {
        Node *new_node = new Node(num);
        new_node->next = head;
        head=new_node;
        sz++;
    }

    void pop_front() {
        if(!sz) {
            cout<<"Deque Empty\n";
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
        while(sz) pop_back();
    }
    
    int front() {
        if(!sz) {
            cout<<"Deque empty\n";
            return -1;
        }
        return head->data;
    }

    int back() {
        if(!sz) {
            cout<<"Deque empty\n";
            return -1;
        }
        return tail->data;
    }
};

class circular_deque_using_arr {
    int *arr, st, en, sz, cap;

public: 
    circular_deque_using_arr(int cap) {
        arr = new int[cap];
        st=0; en=-1; sz=0, this->cap=cap;
    }

    void push_back(int num) {
        if(sz==cap) {
            cout<<"Queue full, kl ana"<<endl;
            return;
        }

        if(sz==0) {
            st=en=0;
            sz=1;
            arr[st]=num;
            return;
        }

        en=(en+1)%cap;
        arr[en]=num;
        sz++;
    }

    void push_front(int num) {
        if(sz==cap) {
            cout<<"Queue full, kl ana"<<endl;
            return;
        }

        if(sz==0) {
            st=en=0;
            sz=1;
            arr[st]=num;
            return;
        }

        st=(st-1 + cap)%cap; // to make sure the number is positive
        arr[st]=num;
        sz++;
    }

    void pop_front() {
        if(!sz) {
            cout<<"Deque khali!"<<endl;
            return;
        }

        st=(st+1)%cap;
        sz--;
    }

    void pop_back() {
        if(!sz) {
            cout<<"Deque Khali!\n";
            return;
        }

        en=(en-1+cap)%cap;
        sz--;
    }

    int front() {
        if(sz) 
            return arr[st];
        cout<<"Queue empty"<<endl;
        return -1;
    }

    int back() {
        if(sz) 
            return arr[en];
        cout<<"Queue Empty"<<endl;
        return -1;
    }

    int size() {return sz;}

    bool empty() {return (sz==0);}

    void clear() {
        while(sz)
            pop_back();
    }
};

// implement a stack using only queue.
// ans - > 

// use 2 queues 

// method 1
// push O(n), pop O(1)
// main and auxilliary
// main: 
// auxilliary: 
// push - transfer all from main to aux, push to main, transfer back from aux to main.
// pop - pop the front.

// method 2
// push in O(1)
// pop in O(n) 
// - transfer all except the last from main to aux, then pop out the element, transfer back to main.


// using 1 queue
// push - simple q.push() O(1)
// pop - O(n)
/*
int n=q.size();
n--;
while(n--) {
    q.push(q.front());
    q.pop();
}
q.pop();
*/ 


// Queue using stack(s)

// 2 stacks i lgenege...............
// O(N) pop, O(1) push
// O(1) pop, O(N) push
// similar to stack using queue


// O(1) both

// push = push in stack 1 
/*
q.push(num) => in.push(num)
*/
// pop
// check the stack 2 to be empty..
// move all elements to 2
// pop the top element
// repeat
/*
q.pop() =>

if(out.empty()) {
    while(in.size()) {
        out.push(in.top()), in.pop();
    }
}

if(out.size()) {
    out.pop();
} else {
    cout<<"khali"<<endl;
}
*/


// negative modulo problem
// a%m = ((a%m)+m)%m;

// given two numbers l and r
// 1 <= l <= r <= 10**12
// print all number form l to r, which have only 2, 3 or 5 as their digits
void digitProblem(int l, int r) {
    queue<int> q;
    vector<int> ans;

    q.push(2);
    q.push(3);
    q.push(5);

    while(q.front()<=r) {
        int n=q.front();
        q.pop();
        if(n>=l) {
            ans.push_back(n);
        }
        q.push(10*n+2), q.push(10*n+3), q.push(10*n+5);
    }
}


int32_t main() {
    circular_queue_using_arr q(5);
    // custom_queue_LL q;
    int n=5;
    for(int i=0; i<n; i++) {
        q.push(i);
    }
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.size()<<endl;
    q.clear();
    cout<<q.size()<<endl;

    custom_deque_LL d;
    for(int i=0; i<n; i++) d.push_back(i);

    cout<<d.front()<<endl;
    d.pop_front();
    cout<<d.size()<<endl;
    d.pop_back();
    cout<<d.size()<<endl;
    cout<<d.back()<<endl;
    return 0;
}