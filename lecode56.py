from typing import List
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        res = []
        last = -210000000
        cur = 210000000
        n = len(intervals)
        intervals.sort(key=lambda x : x[0])
        for i in range(1,n):
            if cur < intervals[1][0]:
                res.append({last,cur})
                last = intervals[1][0]
                cur = intervals[1][1]
                continue
            if cur < intervals[1][1]:
                cur = intervals[1][1]
        res.append({last,cur})
        return res