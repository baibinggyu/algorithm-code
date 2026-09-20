from functools import cache
from collections import Counter
class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        # 记忆化搜索
        if len(s1) != len(s2):
            return False
        @cache
        def dfs(index01 : int ,index02 : int,length : int):
            if s1[index01 : index01 + length] == s2[index02 : index02 + length]:
                return True
            if Counter(s1[index01 : index01 + length]) != Counter(s2[index02 : index02 + length]):
                return False
            for i in range(1,length):
                if dfs(index01,index02,i) and dfs(index01 + i,index02 + i,length - i) : 
                    return True
                if dfs(index01,index02 + length  - i,i) and dfs(index01  + i,index02,length -i):
                    return True
            return False
        res = dfs(0,0,len(s1))
        dfs.cache_clear()
        return res