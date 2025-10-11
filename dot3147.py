n = int(input())
arr = list(map(int,input().split()))
res = 0
dp = [0 for _ in range(n)]
dp[0] = arr[0]  
for i in range(1,n):
    dp[i] = dp[i - 1] ^ arr[i]
for i in range(1,n):
    for j in range(i,n):
        res += dp[j] ^ dp[i - 1]
for val in dp:
    res += val
print(res) 