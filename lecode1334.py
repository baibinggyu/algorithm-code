from typing import List
class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        dp = [[0x3f3f3f3f for _ in range(n)] for _ in range(n)]
        for i in range(n) :
            dp[i][i] = 0
        for val in edges:
            dp[val[0]][val[1]] = val[2]
            dp[val[1]][val[0]] = val[2]
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j])
        res = [0 for i in range(n)]
        for i in range(n):
            for j in range(n):
                if dp[i][j] <= distanceThreshold:
                    res[i] += 1
        ret = n - 1
        for i in range(n - 2,-1,-1):
            if res[ret] > res[i]:
                ret = i
        return ret
