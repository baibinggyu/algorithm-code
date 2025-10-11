from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root == None:
            return True
        left = []
        right = []
        def leftDfs(node : Optional[TreeNode]):
            left.append(node)
            if node == None:
                return
            leftDfs(node.left)
            leftDfs(node.right)
        def rightDfs(node : Optional[TreeNode]):
            right.append(node)
            if node == None:
                return
            rightDfs(node.right)
            rightDfs(node.left)
        leftDfs(root.left)
        rightDfs(root.right)
        if len(left) != len(right):
            return False
        for l , r in zip(left,right):
            if l == r == None:
                continue
            if not (l and r):
                return False
            if l.val != r.val:
                return False
        return True