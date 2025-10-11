import sys
input = sys.stdin.readline
m , n = list(map(int,input().split()))
dp = [0] * (m + 1)
groups = dict() 
for i in range(n):
    a , b , c = list(map(int,input().split()))
    if c not in groups:
        groups[c] = []
    groups[c].append([a,b])
for g in groups:
    for i in range(len(dp) - 1,-1,-1):
        for w , v in groups[g]:
            if i - w >= 0:
                dp[i] = max(dp[i],dp[i - w] + v)

print(dp[-1])