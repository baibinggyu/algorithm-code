class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n , m = len(s) , len(t)
        dp = [[0 for _ in range(n)] for _ in range(m)]
        initial = 0
        if s[0] == t[0]:
            initial += 1
            dp[0][0] = initial
        for i in range(1,n):
            if s[i] == t[0]:
                initial += 1
                dp[0][i] = initial
            else:
                dp[0][i] = dp[0][i - 1]
        for i in range(1,m):
            for j in range(i,n):
                if t[i] == s[j]:
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1]
                else:
                    dp[i][j] = dp[i][j - 1]
        return dp[-1][-1]
