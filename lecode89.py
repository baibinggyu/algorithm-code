from typing import List
class Solution:
    def grayCode(self, n: int) -> List[int]:
        res = [0]
        while n:
            n -= 1
            for i in range(len(res) - 1,-1,-1):
                res[i] <<= 1
                res.append(res[i] + 1)
        return res