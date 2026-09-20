from typing import List
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        coins.sort()
        dp = [0x3f3f3f3f] * (amount + 1)
        dp[0] = 0
        for i in range(amount + 1):
            for val in coins:
                if i + val > amount:
                    break
                dp[i + val] = min(dp[i + val],dp[i] + 1)
        return dp[-1] if dp[-1] != 0x3f3f3f3f else  -1