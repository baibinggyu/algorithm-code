from typing import List
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stk = []
        index = []
        n = len(temperatures)
        res = [0] * n
        for i,val in enumerate(temperatures):
            if len(stk) and stk[-1] < val:
               while len(index) and stk[-1] < val:
                   res[index[-1]] = i - index[-1]
                   index.pop()
                   stk.pop() 
            stk.append(val)
            index.append(i)
        return res