from typing import List
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        nums.sort()
        dp = [0] * (target + 1)
        dp[0] = 1
        for i in range(len(dp)):
            for val in nums:
                if i >= val:
                    dp[i] += dp[i - val]
        return dp[-1]