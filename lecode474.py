from typing import List
import collections
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[[0 for _ in range(n + 1)] for _ in range(m + 1)] for _ in range(len(strs) + 1)]
        for i in range(1,len(strs) + 1):
            cnt = collections.Counter(strs[ i - 1])
            for j in range(m + 1):
                for k in range(n + 1):
                    if cnt['0'] > j or cnt['1'] > k:
                        dp[i][j][k] = dp[i - 1][j][k]
                    else:
                        dp[i][j][k] = max(dp[i - 1][j][k],dp[i - 1][j - cnt['0']][k - cnt['1']] + 1)
        return dp[-1][-1][-1]