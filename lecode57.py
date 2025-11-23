from typing import List
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        n = len(intervals)
        last = newInterval[0]
        cur = newInterval[1]
        res = []
        flag = True
        for inter in intervals:
            if flag:
                if last <= inter[0] and cur >= inter[0]:
                    cur = max(cur,inter[1]) 
                    continue
                elif last >= inter[0] and last <= inter[1]:
                    cur = max(cur,inter[1])
                    last = inter[0]
                    continue
                if cur < inter[0]:
                    res.append([last,cur])
                    flag = False
                    res.append(inter)
                    continue
            res.append(inter)

        if flag:
            res.append([last,cur])
        return res
                
            