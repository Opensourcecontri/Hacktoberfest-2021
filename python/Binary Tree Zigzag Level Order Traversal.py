# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return None
        
        level = 0
        res = []
        self.zzHelper(root, level, res)
        return res
        
    def zzHelper(self,root, level, res):
        if not root:
            return None
        if len(res) < level +1:
                res.append([])
        if level %2 == 1:
            res[level].append(root.val)
        else:
            res[level].insert(0,root.val)
        self.zzHelper(root.right, level+1, res)
        self.zzHelper(root.left, level+1, res)
        

 # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return None
        res = []
        q = [root]
        while q:
            l = []
            n = len(q)
            for i in range(n):
                curr = q.pop(0)
                l.append(curr.val)
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
            if len(res)%2:
                #print(len(res))
                l=l[::-1]
            res.append(l)
        return res
