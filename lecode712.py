class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        n , m = len(s1) , len(s2)
        dp = [[0x3f3f3f3f for _ in range(n + 1)] for _ in range(m + 1)]
        dp[0][0] = 0
        for i in range(1,n):
            dp[0][i] = dp[0][i - 1] + ord(s1[i - 1])
        for i in range(1,m):
            dp[i][0] = dp[i - 1][0] + ord(s2[i - 1])
        for i in range(0,m):
            for j in range(0,n):
                if s2[i] == s1[j]:
                    dp[i + 1][j + 1] = dp[i][j]
                else:
                    dp[i + 1][j + 1] = min(dp[i][j + 1] + ord(s2[i]),dp[i + 1][j] + ord(s1[j]))
        return dp[-1][-1]
if __name__ == "__main__":
    s1 = "sea"
    s2 = "eat"
    test = Solution()
    print(test.minimumDeleteSum(s1,s2))