MOD = 2 ** 64
count = int(input())
out = []
while count:
    n,m,q = map(int,input().split())
    arr = []
    for i in range(n):
        arr.append(list(map(int,input().split())))
    dp = [[0 for _ in range(m)] for _ in range(n)]
    dp[0][0] = arr[0][0]
    for i in range(1,m):
        dp[0][i] = dp[0][i - 1] + arr[0][i]
    for i in range(1,n):
        dp[i][0] = dp[i - 1][0] + arr[i][0]
    for i in range(1,n):
        for j in range(1,m):
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j]
    res = 0
    for i in range(q):
        u,v,x,y = (int(a) - 1 for a in input().split() )
        temp = dp[x][y]
        if u - 1 >= 0:
            temp -= dp[u - 1][y]
        if v - 1 >= 0:
            temp -= dp[x][v - 1]
        if u - 1 >= 0 and v - 1 >= 0:
            temp += dp[u - 1][v - 1]
        res ^= temp % MOD
    out.append(res)
    count -= 1
for val in out:
    print(val)