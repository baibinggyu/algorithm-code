class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 0 or n < 0:
            return False
        SIZE = 31
        flag = 0
        for i in range(SIZE):
            if n & 1:
                flag += 1
            if flag == 2:
                return False
            n >>= 1
        return True