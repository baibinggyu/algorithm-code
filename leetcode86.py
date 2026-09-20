from typing import List,Optional 
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        left_duummy,right_dummy = ListNode(0),ListNode(0)
        left,right = left_duummy,right_dummy
        cur = head
        while cur :
            if cur.val < x:
                left.next = cur
                left =  left.next
            else :
                right.next = cur
                right = right.next
            cur = cur.next
        right.next = None
        left.next = right_dummy.next
        return left_duummy.next

