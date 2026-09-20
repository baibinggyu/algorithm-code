from typing import List
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # 异或和
        xor = 0
        for val in nums:
            xor ^= val
        return xor