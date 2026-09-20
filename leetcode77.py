from typing import List
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []
        def dfs(temp : List[int] ,res : List[List[int]],current : int ,n :int,k : int):
            if len(temp) == k:
                res.append(temp.copy())
                return
            for i in range(current,n + 1):
                temp.append(i)
                dfs(temp=temp,res=res,current=i + 1,n=n,k=k)
                temp.pop()
                
        temp = []
        dfs(temp,res,1,n,k)
        return res