from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        x = y = pre = None
        def inorder(node : Optional[TreeNode]):
            nonlocal x , y , pre
            if node == None:
                return
            inorder(node.left)
            if(pre and node.val < pre.val):
                y = node
                if x == None:
                    x = pre
            pre = node
            inorder(node.right)
        inorder(root)
        x.val ,y.val = y.val ,x.val