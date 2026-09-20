from typing import List, Optional
import collections
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None: 
            return []
        if root.left is None and root.right is None:
            return [[root.val]]
        res = []
        queue = collections.deque([root])
        # True 顺着 , False 逆着
        flag : bool = False
        while queue:
            temp = list()
            for value in queue:
                temp.append(value.val)
            res.append(list(temp))
            curList = queue.copy()
            queue.clear()
            curList.reverse()
            if flag:
                for value in curList:
                    cur = value
                    if cur.left is not None:
                        queue.append(cur.left)
                    if cur.right is not None:
                        queue.append(cur.right)
            else:
                for value in curList:
                    cur = value
                    if cur.right is not None:
                        queue.append(cur.right)
                    if cur.left is not None:
                        queue.append(cur.left)
            flag = not flag
        return res
