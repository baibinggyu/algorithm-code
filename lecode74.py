from typing import List
# 二分查找
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        cols = len(matrix[0])
        n = (rows) * (cols) - 1
        l = 0
        r = n
        while l <= r:
            mid = (r + l) >> 1
            midRows = mid // cols
            midCols = mid % cols
            if matrix[midRows][midCols] == target: 
                return True
            elif matrix[midRows][midCols] < target:
                l = mid + 1
            else: r = mid - 1
        return False