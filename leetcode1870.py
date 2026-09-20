from typing import List
import math
class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        def check(t : int)->bool:
            time = 0.0
            for i in range(0,len(dist) - 1):
                time += math.ceil(dist[i] / t)
            time += dist[-1] / t
            return time <= hour
        l,r = 1 , 10**9 + 1
        while l < r:
            mid = l + ((r - l) >> 1)
            if check(mid):
                r = mid
            else:
                l = mid + 1
        return r if check(r) else -1