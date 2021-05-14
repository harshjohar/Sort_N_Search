#include<bits/stdc++.h>
using namespace std;
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

// you are given a doubly linked list, find middle element
    int middle() {
        Node *slow=head, *fast=head->next;
        while(fast!=NULL && fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
    }

// find median of sorted list
    double median() {
        if(!head) return -1;
        Node *slow=head, *fast=head, *prev_slow=NULL;
        while(fast and fast->next) {
            prev_slow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        if(!fast) {
            return (prev_slow->data + slow->data)/2.0;
        }
        return slow->data;
    }

// reverse a single LL in groups of k
    Node* reverse_by_parts(Node *curr_head, int k) {

        if(!curr_head) return NULL;

        Node *curr=curr_head, *prev=NULL;
        int cnt=0;
        while(curr and cnt<k) {
            Node *next_node = curr->next;
            curr->next = prev;

            prev=curr;
            curr=next_node;
            cnt++;
        }

        // curr-> (k+1) pos
        curr_head->next = reverse_by_parts(curr, k);
        return prev;
    }
};

int32_t main() {
    DoublyLinkedList l;
    for(int i=1; i<=7; i++) l.push_back(i);
    l.printLL();

    cout<<l.middle()<<endl;
    cout<<l.median()<<endl;
    Node* new_head=l.reverse_by_parts(l.head, 3);
    l.head=new_head;
    l.printLL();
}

