class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        MOD = 10 ** 9 + 7
        dp = [0] * (high + 1)
        dp[zero] = 1
        dp[one] += 1
        for i in range(high + 1):
            if i - zero >= 0:
                dp[i] += dp[i - zero]
            if i - one >= 0:
                dp[i] += dp[i - one]
        
        res = 0 
        for i in range(low,high + 1):
            res = (res % MOD + dp[i] % MOD ) % MOD
        return res
            