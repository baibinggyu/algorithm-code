# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
from typing import Optional
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None : return False 
        if root.left is None and root.right is None: return True if root.val is targetSum else False 
        return self.bfs(root.left,root.val,targetSum) or self.bfs(root.right,root.val,targetSum) 
    def bfs(self,cur :TreeNode | None,num_sum : int,targetSum : int) -> bool:
        if cur is None : return False
        num_sum += cur.val
        if cur.left is None and cur.right is None and num_sum == targetSum: return True
        return self.bfs(cur.left,num_sum,targetSum) or self.bfs(cur.right,num_sum,targetSum) 