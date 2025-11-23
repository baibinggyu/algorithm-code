from typing import List
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        stk = []
        nums.sort()
        def dfs(curIndex : int):
            if not (stk in res):
                res.append(list(stk))
            for i in range(curIndex,len(nums)):
                stk.append(nums[i])
                dfs(i + 1)
                stk.pop()
        dfs(0)
        return res
    
if __name__ == "__main__":
    ans = Solution()
    arr = [4,4,4,1,4]
    print(ans.subsetsWithDup(arr))