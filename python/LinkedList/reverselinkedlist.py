#Iterative approach:
def reverse(headNode):
 if headNode==None:
 return None
 elif headNode.next==None:
 return headNode
 prev=headNode
 curr=prev.next
 next=curr.next
 prev.next None
 while next:
 curr.next = prev
 prev = curr
 curr = next
 next = next.next
 curr.next = prev
#recursion
def reverse2(head):
if head is None or head.next is None:
return head, head
smallHead,smallTail = reverse2(head.next)
smallTail.next= head
head.next = None
return smallHead,head
