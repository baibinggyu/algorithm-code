from typing import Optional,List
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root == None:
            return []
        res = []
        que = deque()
        que.append(root)
        while que:
            ans = []
            n = len(que)
            for i in range(n):
                cur = que.popleft()
                if cur.left:
                    que.append(cur.left)
                if cur.right:
                    que.append(cur.right)
                ans.append(cur.val)
            res.append(list(ans))
        return res