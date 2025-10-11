from typing import List
class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        dp = [[0 if _ == 0 else questions[i][0] for _ in range(2)] for i in range(len(questions))]
        # achive -> 1 , pass -> 0
        indexMax = len(questions) - 1
        print(dp[-1])
        for i in range(indexMax - 1,-1,-1):
            dp[i][0] = max(dp[i + 1][0],dp[i + 1][1])
            if i + questions[i][1] < indexMax:
                dp[i][1] = max(dp[i + questions[i][1] + 1][1],dp[i + questions[i][1]][0]) + dp[i][1]
        return max(dp[0][0],dp[0][1])        