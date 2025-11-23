from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        select = dict()
        select[None] = 0
        unSelect = dict()
        unSelect[None] = 0
        def bfs(node : Optional[TreeNode]):
            if node == None:
                return
            bfs(node.left)
            bfs(node.right)
            select[node] = unSelect[node.left] + unSelect[node.right] + node.val
            unSelect[node] = max(select[node.left],unSelect[node.left]) + max(select[node.right],unSelect[node.right])
        bfs(root)
        return max(select[root],unSelect[root])