from typing import List
class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        prime = []
        isPrime = [True] * (right + 1)
        isPrime[1] = False
        for i in range(2,right + 1):
            if isPrime[i]:
                prime.append(i)
            for val in prime:
                if val * i > right:
                    break
                isPrime[val * i] = False
                if i % val == 0:
                    break 
        res = []
        for idx in range(left , right + 1):
            if isPrime[idx]:
                res.append(idx)
        if len(res) < 2:
            return [-1,-1]
        resIndex = [res[0],res[1]]
        for i in range(2,len(res)):
            if resIndex[1] - resIndex[0] > res[i] - res[i - 1]:
                resIndex[1] = res[i]
                resIndex[0] = res[i - 1]
        return resIndex
        