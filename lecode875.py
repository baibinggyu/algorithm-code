from typing import List
import math
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def check(t : int)->bool:
            time = 0.0
            for i in range(0,len(piles) - 1):
                time += math.ceil(piles[i] / t)
            time += piles[-1] / t
            return time <= h
        l = 1
        r = 10 ** 9 + 1
        while l < r:
            mid = l + ((r - l) >> 1)
            if check(mid):
                r = mid
            else:
                l = mid + 1
        return r if check(r) else -1 