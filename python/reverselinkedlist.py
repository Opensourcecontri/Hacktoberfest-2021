from sys import stdin , setrecursionlimit
setrecursionlimit(10**6)
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Taking Input Using Fast I/O
def takeInput() :
    head = None
    tail = None

    datas = list(map(int, stdin.readline().rstrip().split(" ")))

    i = 0
    while (i < len(datas)) and (datas[i] != -1) :
        data = datas[i]
        newNode = Node(data)

        if head is None :
            head = newNode
            tail = newNode

        else :
            tail.next = newNode
            tail = newNode

        i += 1


    return head


# To print the linked list 
def printLinkedList(head) :

    while head is not None :
        print(head.data, end = " ")
        head = head.next

    print()


def reverse(head):
    # Write your code here
    if head is None:
         return head
    c=head
    p=None
    while c:
         next=c.next
         c.next=p
         p=c
         c=next
    return p
    












# Main
t = int(stdin.readline().rstrip())

while t > 0 :

    head = takeInput()
    
    ans=reverse(head)
    printLinkedList(ans)

    t -= 1 
