from typing import List
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0];
        dp = [-2100000000 for _ in range(n)]
        dp[0] = nums[0]
        for i in range(1,n):
            dp[i] = max(nums[i],nums[i] + dp[i-1])
        return max(dp)