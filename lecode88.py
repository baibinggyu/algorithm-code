from typing import List
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        while len(nums1) > m:
            nums1.pop()
        while len(nums2) > n:
            nums2.pop()
        index02 = 0
        pCount = 0
        for i in range(m):
            if index02 >= len(nums2):
                break
            while nums1[i + pCount] >= nums2[index02]:
                nums1.insert(i + pCount,nums2[index02])
                index02 += 1
                pCount += 1
        while index02 < len(nums2):
            nums1.append(nums2[index02])
            index02 += 1
    
