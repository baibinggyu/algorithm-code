from typing import List
class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        MOD = 1337
        res = 1 
        num = int("".join(str(x) for x in b))
        while num:
            if num & 1 :
                res *= a
                res = res % MOD
            a *= a
            a  = a % MOD
            num = num >> 1

        return res

