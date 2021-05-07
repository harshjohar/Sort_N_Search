# Implementation of linked list
class Node:
	data = -1
	next = None

	def __init__(self, data):
		self.data = data


def display_LL(head):
	temp = head
	while temp != None:
		print(temp.data, end = " ")
		temp = temp.next

	print()
	return

def length_of_LL(head):
	temp = head
	sz = 0
	while temp != None:
		sz += 1
		temp = temp.next

	return sz

def insert_at_head(head, data):
	if head == None:
		return Node(data)
		 
	new_node = Node(data)
	new_node.next = head
	head = new_node
	return head

def insert_at_tail(head, data):
	if head == None:
		return Node(data)
	temp = head
	while temp.next != None:
		temp = temp.next

	new_node = Node(data)
	temp.next = new_node
	return head


def insert_at(head, data, pos = 0):
	if pos == 0:
		return insert_at_head(head, data)
	if pos >= length_of_LL(head):
		return insert_at_tail(head, data)

	temp = head
	while pos != 1:
		pos -= 1
		temp = temp.next

	new_node = Node(data)
	new_node.next = temp.next
	temp.next = new_node
	return head

def delete_at_head(head):
	if head == None:
		return None
	temp = head
	head = head.next
	temp.next = None
	return head	

def delete_at_tail(head):
	temp = head
	prev = None
	while(temp.next != None):
		prev = temp
		temp = temp.next

	# when this loop ends temp points at the tail and prev at the prev node to the tail
	prev.next = None
	return head

def delete_At(head, pos = 0):
	if pos == 0:
		return delete_at_head(head)
	if pos >= length_of_LL(head):
		return delete_at_tail(head)

	temp = head
	while pos != 1:
		pos -= 1
		temp = temp.next

	tobedeleted = temp.next
	temp.next = temp.next.next
	tobedeleted.next = None
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



n=int(input())
head=None
while n>0:
    n-=1
    x=int(input())
    head=insert_at_tail(head, x)
    # print(head.data)
head = insert_at(head, 33, 4)
display_LL(head)
delete_at_head(head)
display_LL(head)
delete_at_tail(head)
display_LL(head)
delete_at(head, 2)
display_LL(head)