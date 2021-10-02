class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root :
            return True
        left=root.left
        right=root.right
        return self.isSame(left,right);
    
    def isSame(self,left:TreeNode,right:TreeNode) -> bool:
        if(not left and not right):
            return True
        if(not left or not right):
            return False
        else:
            if left.val != right.val:
                return False
        return self.isSame(left.right,right.left) and self.isSame(left.left,right.right)


class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        q = [root,root]
        while q:
            t1 = q.pop(0)
            t2 = q.pop(0)
            if not t1 and not t2:
                continue
            if not t1 or not t2 or t1.val != t2.val:
                return False
            q.append(t1.left)
            q.append(t2.right)
            q.append(t1.right)
            q.append(t2.left)
        return True
