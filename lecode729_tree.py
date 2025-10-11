# 动态线段树
class SegmentTree:
    def __init__(self):
        self.left = None
        self.right = None
        self.booked = False
        self.lazy = False

class MyCalendar:

    def __init__(self):
        self.root = SegmentTree()
        self.N = int(1e9 + 5)

    def book(self, startTime: int, endTime: int) -> bool:
        if self.query(self.root,0,self.N,startTime,endTime -1):
            return False
        self.update(self.root,0,self.N,startTime,endTime - 1)
        return True
    
    def query(self,node : SegmentTree,l : int,r : int,targetLeft : int,targetRight : int) -> bool:
        if node is None or (targetRight < l or targetLeft > r):
            return False
        if node.booked:
            return True
        if l == r :
            return node.booked
        mid : int = l + ((r - l) >> 1)
        return self.query(node.left,l,mid,targetLeft,targetRight) or \
            self.query(node.right,mid + 1,r,targetLeft,targetRight)
    
    def update(self,node : SegmentTree,l : int,r : int,targetLeft : int,targetRight : int):
        if node is None: return
        if targetLeft > r or targetRight < l: return
        if targetLeft <= l and r <= targetRight:
            node.booked = True
            node.lazy = True
            return
        self.push_down(node)
        mid : int = l + ((r - l) >> 1)
        self.update(node.left,l ,mid,targetLeft,targetRight)
        self.update(node.right,mid + 1,r,targetLeft,targetRight)
        node.booked = node.left.booked and node.right.booked
    def push_down(self,node : SegmentTree):
        if node.left is None:
            node.left = SegmentTree()
        if node.right  is None:
            node.right = SegmentTree()
        if node.lazy:
            node.left.booked = node.right.booked = True
            node.left.lazy = node.right.lazy = True
            node.lazy = False
    
    
# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(startTime,endTime)