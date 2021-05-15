#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define int long long int
#define endl "\n"


// Tell if it is possible to rearrange the array in such a way that 
// the sum of no 2 cosecutive elements is divisible by 3.

int notDivBy3() {
    int n; cin>>n;
    vi arr(n);
    int c0=0, c1=0, c2=0;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        arr[i]%=3;
        if(arr[i]==0) c0++;
        if(arr[i]==1) c1++;
        if(arr[i]==2) c2++;
    }
    bool valid=true;
    if(c1+c2 >= c0-1) {
        if(c1>0 && c2>0) {
            if(c0>0) {
                return true;
            }
        }
        return true; 
    }
    return 0;
}


// Given a singly LL, end  can be pointing to a node in same LL.
// Check whether a loop exists or not.
/* Link list node */
class Node {
public:
    int data;
    Node* next;
};
 
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
int detectLoop(Node* list)
{
    Node *slow_p = list, *fast_p = list;
 
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}