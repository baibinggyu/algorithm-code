class Solution:
    def numSquares(self, n: int) -> int:
        arr = [0] * (n + 1)
        arr[0] = 0
        arr[1] = 1
        for i in range(1,n + 1):
            minn = 0x3f3f3f3f
            for j in range(1,i + 1):
                jj = j * j
                if jj > i:
                    break
                minn = min(minn,arr[i - jj])
            arr[i] = minn + 1
        return arr[-1]