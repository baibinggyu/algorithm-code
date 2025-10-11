from typing import List
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = l + ((r - l) >> 1)
            if nums[mid] == target:
                return True
            if nums[mid] == nums[r]:
                r -= 1
                continue
            # 半有序
            if nums[mid] < nums[r]:
                if nums[mid] > target:
                    r = mid - 1
                elif nums[mid] < target:    
                    if target > nums[r]:
                        r = mid - 1
                    elif target < nums[r]:
                        l = mid + 1
                    else: 
                        return True
            elif nums[mid] > nums[r]:
                if nums[mid] < target:
                    l = mid + 1
                elif nums[mid] > target:
                    if target > nums[l]:
                        r = mid - 1
                    elif target < nums[l]:
                        l = mid + 1
                    else: 
                        return True
        return False
            