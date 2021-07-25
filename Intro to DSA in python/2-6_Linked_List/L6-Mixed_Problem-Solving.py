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
Given a linked list of integer values in a node, reverse the linked list, by only manipulating the next pointers.
'''
# iterative solution
def reverse_iterative(head):
    if head==None:
        return None
    prev_, curr_, next_ = None, head, head.next

    while next_ != None:
        curr_.next = prev_
        prev_ = curr_
        curr_ = next_
        next_ = next_.next
    curr_.next = prev_
    return curr_

# recursive solution
def reverse_recur(head):
    if head == None or head.next==None:
        return head
    
    tail = reverse_recur(head.next)
    head.next.next = head
    head.next = None
    return tail

'''
Reversing Without manipulating pointers and only replacing data
'''
def fold_helper(left, right):
    if right==None:
        return left
    
    left = fold_helper(left, right.next)
    if left==None:
        return left
    
    if left!=right and left.next != right:
        tmp = left.next
        left.next = right
        right.next = tmp
        left=tmp
    else:
        right.next = None
        left=None

    return left

def fold(head):
    fold_helper(head, head)
    return head


'''
You have a LL, with every node having a next pointer and bottom pointer, flatten the LL
'''


# Driver Code
n = int(input())
head1 = None
while n > 0:
	n -= 1
	x = int(input())
	head1 = insert_at_tail(head1, x)

display_LL(head1)
head2 = reverse_iterative(head1)
display_LL(head2)
head3 = reverse_recur(head2)
display_LL(head3)