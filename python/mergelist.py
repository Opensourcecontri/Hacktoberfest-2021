def MergeLists(headA, headB):
    if headA is None and headB is None:
        return None
    
    if headA is None:
        return headB
    elif headB is None:
        return headA
    
    ret = Node() 
    
    if headA.data < headB.data:
        ret = headA
        ret.next = MergeLists(headA.next, headB)
    else:
        ret = headB
        ret.next = MergeLists(headA, headB.next)
        
    return ret
