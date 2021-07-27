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
Given a linked list with all the node containing digits, check whether the LL is a palindrome or not
'''
left=None
def palindrome(left, right):
    if right!=None:
        result = palindrome(left, right.next)
        left = result[1]
        if not result[0]:
            return (False, left)
        if left.data != right.data:
            return (False, left)
        
        left = left.next
    
    return (True, left)

def check(head1, head2):
    result=palindrome(head1, head2)
    return result[0]


'''
Write merge sort to sort a LL.
'''



#-------------------------------------------------------------------------------------#
n=int(input())
head1 = None
while n>0:
    n-=1
    x=int(input())
    head1 = insert_at_tail(head1, x)

display_LL(head1)
print(check(head1, head1))