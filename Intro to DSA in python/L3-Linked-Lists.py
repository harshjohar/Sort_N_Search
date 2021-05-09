# Implementation of linked list
class Node:
    data=-1
    next=None

    def __init__(self, data):
        self.data=data

    # Adding data in linked lists
    # at head
    # at tail
    # in middle somewhere

def display_LL(head):
    tmp=head
    while tmp!=None:
        print(tmp.data, end=' ')
        tmp=tmp.next
    print()
    return

def length_of_LL(head):
    tmp=head
    sz=0
    while tmp!=None:
        sz+=1
        tmp=tmp.next
    return sz

def insert_at_head(head, data):
    if head == None:
        return Node(data)
    
    new_node = Node(data)
    new_node.next = head
    head = new_node
    return head

def insert_at_tail(head, data):
    if head==None:
        return Node(data)

    tmp=head
    while tmp.next != None:
        tmp=tmp.next

    new_node = Node(data)
    tmp.next = new_node
    return head

def insert_at(head, data, pos=0):
    if pos==0:
        return insert_at_head(head, data)
    
    if pos >= length_of_LL(head):
        return insert_at_tail(head, data)
    
    tmp=head
    while pos != 1:
        pos-=1
        tmp=tmp.next
    
    new_node = Node(data)
    new_node.next = tmp.next
    tmp.next=new_node
    return head

def delete_at_head(head):
    if head==None:
        print("msti nai")
        return None
    tmp=head
    head=head.next
    tmp.next=None
    return head

def delete_at_tail(head):
    if head==None:
        print("msti nai")
        return

    tmp=head
    prev=None
    while tmp.next != None:
        prev=tmp
        tmp=tmp.next

    # tmp is now the tail , prev is second last
    prev.next=None
    return head

def delete_at(head, pos=0):
    if pos==0:
        return delete_at_head(head)
    if pos>=length_of_LL(head):
        return delete_at_tail(head)
    
    tmp=head
    while pos!=1:
        pos-=1
        tmp=tmp.next
    dele=tmp.next
    tmp.next=tmp.next.next
    dele.next=None
    return head

'''
Find mid node of a Linked List without using length function and by iterating only once on the linked list.
TC = O(n)
SC = O(1)
'''

# Hare and tortoise approach
# Fast and Slow pointer
def find_mid_node(head):
    fast, slow = head.next, head
    while fast != None and fast.next != None:
        fast = fast.next.next
        slow = slow.next
    return slow


'''
Your are given two linked lists(only single-digit) of same size, add them and return a new linked list.
'''

def sum_LL_same_size(head1, head2):
    if head1==None or head2==None:
        return (None, 0)
    result = Node(0)
    returned_node, carry = sum_LL_same_size(head1.next, head2.next)
    result.next = returned_node
    sum_ = head1.data + head2.data + carry
    carry = sum_//10
    result.data = sum_%10
    return (result, carry)


def sum_LL(head1, head2):
    result, carry=sum_LL_same_size(head1, head2)
    if carry==0:
        return result
    n=Node(carry)
    n.next = result
    return n

n=int(input())
head1=None
while n>0:
    n-=1
    x=int(input())
    head1=insert_at_tail(head1, x)
m=int(input())
head2=None
while m>0:
    m-=1
    x=int(input())
    head2=insert_at_tail(head2, x)

display_LL(head1)
display_LL(head2)

sum_ = sum_LL(head1, head2)
display_LL(sum_)
    # print(head.data)
# head = insert_at(head, 33, 4)
# display_LL(head)
# head = delete_at_head(head)
# display_LL(head)
# delete_at_tail(head)
# display_LL(head)
# delete_at(head, 2)
# display_LL(head)