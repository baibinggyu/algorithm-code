from typing import List
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        n,m = len(matrix),len(matrix[0])
        dp = [[0 for i in range(m)] for j in range(n)]
        res = 0
        for i in range(n):
            dp[i][0] = int(matrix[i][0])
            if dp[i][0]:
                res = 1
        for i in range(m):
            dp[0][i] = int(matrix[0][i])
            if dp[0][i]:
                res = 1
        for i in range(1,n):
            for j in range(1,m):
                if matrix[i][j] != "1":
                    continue
                dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) + 1
                res = max(res,dp[i][j])
        return res * res