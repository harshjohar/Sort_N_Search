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

    void push_front(int d) {    // insert at front
        Node *new_head = new Node(d);
        if(!head)
            tail=new_head, head=new_head;
        else {
            new_head->next = head;
            head->prev=new_head;
            head = new_head;  
        }
        size++;
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

    void insert_at(Node *curr, int d) {
        Node *new_node = new Node(d);
        new_node->next = curr->next;
        curr->next = new_node; 

        new_node->prev = curr;
        if(new_node->next) {
            new_node->next->prev = new_node;
        }
        else
            tail=new_node;
        size++;
    }

    void pop_back() {
        if(!tail) return;

        if(!(tail->prev)) {
            delete head;

            head=tail=NULL;
        }
        else {
            Node *new_tail = tail->prev;

            new_tail->next = NULL;
            delete tail;
            tail=new_tail;
        }
        size--;
    }

    void pop_front() {
        if(!head) return;
        if(!(head->next)) {
            delete head;
            head=tail=NULL;
        }
        else {
            Node *new_head = head->next;
            new_head->prev=NULL;
            delete head;
            head=new_head;
        }
        size--;
    }

    void pop(Node *curr) {
        // curr is assummed to be valid
        if(size==1) {
            delete curr;
            head=tail=NULL;
        }
        if(curr->prev) {
            curr->prev->next = curr->next;
        }
        if(curr->next) {
            curr->next->prev = curr->prev;
        }

        if(curr==head) {
            head=curr->next;
        }
        if(curr==tail) {
            tail=curr->prev;
        }
        delete curr;
        size--;
    }
    void printLL() {
        Node *curr=head;
        while(curr) {
            cout<<curr->data<<' ';
            curr = curr->next;
        }
        cout<<"\n";
    }

    void printLL_rec_helper(Node *curr) {
        if(!curr) return;
        cout<<curr->data<<" ";
        printLL_rec_helper(curr->next);
    }   

    void printLL_rec() {
        printLL_rec_helper(head);
        cout<<"\n";
    }

    void reverse() {
        Node *curr = head;
        while(curr) {
            swap(curr->next, curr->prev);
            curr=curr->prev;
        }
        swap(head, tail);
    }

    void reverse_singly() {
        Node *curr = head, *prev=NULL;
        while(curr) {
            Node *next_node = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next_node;
        }
        swap(head, tail);
    }
};

int32_t main() {
    DoublyLinkedList l;
    for(int i=0; i<=10; i++) l.push_back(i);
    l.printLL();

    l.pop_back();
    l.printLL();

    l.pop_front();
    l.printLL();

    l.insert_at(l.head, 11);
    l.printLL_rec();

    cout<<l.size<<endl;

    l.reverse();
    l.printLL();

    l.reverse_singly();
    l.printLL();
}