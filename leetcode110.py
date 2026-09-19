class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
from typing import Optional 
# Definition for a binary tree node.
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        flag = self.height(root)
        return False if flag == -1 else True
    def height(self,cur: TreeNode | None) -> int:
        if cur == None: return 0
        if cur.left == None and cur.right == None: return 1
        left = self.height(cur.left)
        if left == -1: return -1
        right = self.height(cur.right)
        if right == -1: return -1
        if abs(left - right) > 1: return -1
        return left + 1 if left > right else right + 1