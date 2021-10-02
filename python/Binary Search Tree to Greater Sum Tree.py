class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.sum = 0
        def dfs(node):
            if not node: return
            dfs(node.right)
            node.val += self.sum
            self.sum = node.val
            dfs(node.left)
            return
        
        dfs(root)
        return root
