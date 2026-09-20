from typing import List
class Solution:
    def dfs(self,nums:List[int],temp:List[int],res:List[List[int]],k:int,size:int,ccurIndex:int):
        if size == k:
            res.append(temp.copy())
            return
        for idx in range(ccurIndex,len(nums)):
            temp.append(nums[idx])
            self.dfs(nums=nums,temp=temp,res=res,k=k,size=size + 1,ccurIndex=idx+1)
            temp.pop()
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = []
        res.append([])
        temp = []
        for loop in range(n):
            
            for idx in range(n):
                temp.append(nums[idx])
                self.dfs(nums=nums,temp=temp,res=res,k=loop+1,size=1,ccurIndex=idx+1)
                temp.pop()
        return res