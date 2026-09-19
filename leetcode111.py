# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
from typing import Optional
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:       
        if root is None: return 0
        return  self.md(root)
    def md(self,cur : TreeNode | None) -> int:
        if cur is None: return 0x3f3f3f3f
        if cur.left is None and cur.right is None : return 1
        left = self.md(cur.left)
        if left is 1: return 2
        right = self.md(cur.right)
        if right is 1: return 2
        return min(left,right) + 1