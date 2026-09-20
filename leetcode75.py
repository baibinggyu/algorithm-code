import math
from typing import List
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        l = 0
        r =  len(nums) - 1
        mid = 0
        while mid <= r:
            if nums[mid] == 0:
                nums[mid],nums[l] = nums[l],nums[mid]
                l += 1
                mid += 1
            elif nums[mid] == 2:
                nums[mid],nums[r] = nums[r],nums[mid]
                r -= 1
            else :
                mid += 1
            
