# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if not nums:
            return None
        left = 0
        right = len(nums)-1
        return self.bstRecursive(nums,left,right)
    
    
    def bstRecursive(self,nums,left,right):
        if left > right:
            return None
        mid = left + (right-left)//2
        curr = TreeNode(nums[mid])
        curr.left = self.bstRecursive(nums,left,mid-1)
        curr.right = self.bstRecursive(nums,mid+1,right)
        
        return curr
