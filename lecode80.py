from typing import List
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return 2
        idx = 2
        for index in range(2,len(nums)):
            if nums[idx - 2] != nums[index]:
                nums[idx] = nums[index]         
                idx += 1
        return idx
