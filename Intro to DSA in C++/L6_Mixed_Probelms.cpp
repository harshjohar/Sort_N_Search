#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

// Your are given a binary array
// You are given queries,(l, r) invert the bits in that range
// indexing is 1-based
int bin_arr() {
    int n; cin>>n;
    vi v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vi pre(n, 0);
    int q; cin>>q;
    while(q--) {
        int l, r; cin>>l>>r;
        pre[l]++;
        pre[r]--;
    }
    for(int i=1; i<n; i++) {
        pre[i]+=pre[i-1];
    }
    for(int i=0; i<n; i++) {
        if(pre[i]%2!=0) {
            v[i]= 1-v[i];
        }
    }
}
int bin_arr_cooldude() {
    int n; cin>>n;
    vi v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vi pre(n, 0);
    int q; cin>>q;
    while(q--) {
        int l, r; cin>>l>>r; l--; r--;
        pre[l]=1-pre[l];
        pre[r+1]=1-pre[r+1];
    }
    for(int i=1; i<n; i++) {
        pre[i]^=pre[i-1];
    }
    for(int i=0; i<n; i++) {
        if(pre[i]) {
            v[i]= 1-v[i];
        }
    }
}

// You are given 2 LL, find their intersection point
// -> Y shaped formation is there

// sol -> start the longer one from l2-l1
// sol -> pointers at end approach
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
// doubly linked list
class DoublyLinkedList {
public:
    Node *head;
    Node *tail;
    int size;
    
    DoublyLinkedList() {
        head = NULL; 
        tail = NULL;
        size = 0;
    }
    void push_back(int d) {     // insert at end
        Node *new_tail = new Node(d);

        if(tail==NULL)
            head=new_tail, tail=new_tail;
        else{
            tail->next = new_tail;
            new_tail->prev = tail;
            tail=new_tail;
        }
        size++;
    }
    void printLL() {
        Node *curr=head;
        while(curr) {
            cout<<curr->data<<' ';
            curr = curr->next;
        }
        cout<<"\n";
    }
};

int getCount(Node *head) {
    Node *curr = head;
    int cnt=0;
    while(curr!=NULL) {
        cnt++;
        curr=curr->next;
    }
    return cnt;
}

int _getIntesectionNode(int d, Node* head1, Node* head2)
{
    // Stand at the starting of the bigger list
    Node* current1 = head1;
    Node* current2 = head2;
  
    // Move the pointer forward
    for (int i = 0; i < d; i++) {
        if (current1 == NULL) {
            return -1;
        }
        current1 = current1->next;
    }
  
    // Move both pointers of both list till they
    // intersect with each other
    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2)
            return current1->data;
  
        // Move both the pointers forward
        current1 = current1->next;
        current2 = current2->next;
    }
  
    return -1;
}

int getIntesectionNode(Node* head1, Node* head2)
{
  
    // Count the number of nodes in
    // both the linked list
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;
  
    // If first is greater
    if (c1 > c2) {
        d = c1 - c2;
        return _getIntesectionNode(d, head1, head2);
    }
    else {
        d = c2 - c1;
        return _getIntesectionNode(d, head2, head1);
    }
}


// AMAZON CHOICE
// Clone a ll, 
// Each node has a data, next and random
class node_a {
public:
    int data;
    node_a *next;
    node_a *random;
    node_a *prev;
    node_a(int d) {
        data = d;
        next=NULL;
        random=NULL;
        prev=NULL;
    }
};

class LinkedList {
public:
    node_a *head;
    node_a *tail;
    int size;

    LinkedList() {
        head=NULL;
        tail=NULL;
        size=0;
    }
    void push_back(int d) {     // insert at end
        node_a *new_tail = new node_a(d);

        if(tail==NULL)
            head=new_tail, tail=new_tail;
        else{
            tail->next = new_tail;
            new_tail->prev = tail;
            tail=new_tail;
        }
        size++;
    }
    void printLL() {
        node_a *curr=head;
        cout<<"LL: ";
        while(curr) {
            cout<<curr->data<<' ';
            cout<<"Random: "<<curr->random<<", ";
            curr = curr->next;
        }
        cout<<"\n";
    }
    node_a *clone(node_a *head) {
        node_a* curr = head, *tmp;
        while(curr) {
            tmp=curr->next;

            curr->next=new node_a(curr->data);
            curr->next->next=tmp;
            curr=tmp;
        }
        curr=head;

        while(curr) {
            if(curr->next) 
                curr->next->random=curr->random?curr->random->next:curr->random;
            
            curr=curr->next?curr->next->next:curr->next;
        }
        node_a *original = head, *copy=head->next;

        tmp=copy;

        while(original && copy) {
            original->next = original->next? original->next->next:original->next;

            copy->next = copy->next? copy->next->next: copy->next;
            original = original->next;
            copy= copy->next;
        }
        return tmp;
    }
};