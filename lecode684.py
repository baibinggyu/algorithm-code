from typing import List
class Solution:
    # 暴力
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        father = [x for x in range(n + 1)]
        def find(x :int):
            if father[x] == x:
                return x
            father[x] = find(father[x])
            return father[x]
        def union(m : int,n : int):
            m = find(m)
            n = find(n)
            if m == n :
                return
            elif m < n :
                father[n] = m
            else :
                father[m] = n
        index = -1
        res = []
        for i in range(n):
            for idx,val in enumerate(edges):
                if i == idx :
                    continue
                union(val[0],val[1])
            temp = 0
            for j in range(1,n + 1):
                if father[j] == j :
                    temp += 1
            if temp == 1:
                res.append(edges[i])
            father = [x for x in range(n + 1)]
        return res[-1]

