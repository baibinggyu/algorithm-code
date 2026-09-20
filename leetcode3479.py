from typing import List
class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        res = 0 
        tree = [0] * (4 * len(fruits))
        def build(idx : int,left : int,right : int):
            if left == right:
                tree[idx] = baskets[left]
                return baskets[left]
            mid = left + ((right - left) >> 1)
            lValue = build(idx * 2,left,mid)
            rValue = build(idx * 2 + 1,mid + 1,right)
            tree[idx] = max(lValue,rValue)
            return tree[idx]
        build(1,0,len(baskets) - 1)
        def treeSearchAndUpadate(idx : int,left : int,right : int,target : int):
            if  tree[idx] < target:
                return -1
            if left == right:
                tree[idx] = -1
                return left
            mid = left + ((right - left) >> 1)
            find = treeSearchAndUpadate(idx * 2,left,mid,target)
            if find == -1:
                find = treeSearchAndUpadate(idx * 2 + 1,mid + 1,right,target)
            tree[idx] = max(tree[idx * 2],tree[idx * 2 + 1])                
            return find
        for i in range(len(fruits)):
            if treeSearchAndUpadate(1,0,len(baskets) - 1,fruits[i]) == - 1:
                res += 1
        return res

if __name__ == "__main__":
    test = Solution()
    fruits = [98,63]
    baskets = [67,85]
    print(test.numOfUnplacedFruits(fruits,baskets))
