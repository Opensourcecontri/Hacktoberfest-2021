class Solution:
    def goodNodes(self, root: TreeNode, mx = float('-inf')) -> int:
        if not root:
            return 0
        if root.val >= mx:
            return 1 + self.goodNodes(root.left, root.val) + self.goodNodes(
                root.right, root.val)
        else:
            return self.goodNodes(root.left,mx) + self.goodNodes(root.right,mx)
        


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        count = 0
        q = [(root,-inf)]
        while q: 
            node,val = q.pop(0)
            if node.val >= val:
                val = node.val
                count +=1
            if node.left:
                q.append((node.left,val))
            if node.right:
                q.append((node.right,val))
        return count
