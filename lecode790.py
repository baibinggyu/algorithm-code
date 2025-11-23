class Solution:
    def numTilings(self, n: int) -> int:
        MOD = 10 ** 9 + 7
        dp  = [[[0] for _ in range(4)] for _ in range(n)]
        dp[0][0] = 1
        dp[0][1] = 0
        dp[0][2] = 0
        dp[0][3] = 1
        for i in range(1,n):
            dp[i][0] = dp[i - 1][3]
            dp[i][1] = dp[i - 1][2] + dp[i -1][0]
            dp[i][2] = dp[i - 1][1] + dp[i - 1][0]
            dp[i][3] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]
        return dp[-1][-1] % MOD