from typing import List
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        left = [-1] * n
        right = [n] * n
        stk = []
        for i in range(n):
            if stk and heights[stk[-1]] > heights[i]:
                while(stk and heights[stk[-1]] > heights[i]):
                    right [stk[-1]] = i
                    stk.pop()
            stk.append(i)
        stk.clear()
        for i in range(n - 1,-1,-1):
            if stk and heights[stk[-1]] > heights[i]:
                while(stk and heights[stk[-1]] > heights[i]):
                    left[stk[-1]] = i
                    stk.pop()
            stk.append(i)
        res = 0
        for i in range(n):
            res = max(res,heights[i] * (right[i] - left[i] - 1))
        return res