from typing import List, Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if len(nums) == 0: 
            return None
        return self.buildTree(nums,0,len(nums) - 1)
    def buildTree(self,nums: List[int], left: int, right: int) -> Optional[TreeNode]:
        if left > right:
            return None
        if left == right:
            return TreeNode(nums[left])
        mid = (right - left) // 2 + left
        cur : Optional[TreeNode] = TreeNode(nums[mid])
        leftNode = self.buildTree(nums,left,mid - 1)
        rightNode = self.buildTree(nums,mid + 1,right)
        cur.left , cur.right = leftNode, rightNode
        return cur