import sys
input = sys.stdin.readline
n , m = list(map(int,input().split()))
groups = {}
dp = [0] * (n + 1)
table = [0] * m
cnt = 0
for i in range(1,m + 1):
    v , p , q = list(map(int,input().split()))
    if q == 0:
        if i not in groups:
            groups[i] = [[v,p]]
        else:
            groups[i].append([v,p])
    else:
        groups[q].append([v,p]) 
for g in groups:
    hash = [False] * (n + 1)
    for i in range(n,-1,-1):
        if i - groups[g][0][0] >= 0:
            if dp[i - groups[g][0][0]] + groups[g][0][1] * groups[g][0][0] > dp[i]:
                hash[i] = True 
                dp[i] = dp[i - groups[g][0][0]] + groups[g][0][1] * groups[g][0][0]
    for i in range(1,len(groups[g])):
        for j in range(n,-1,-1):
            if j - groups[g][i][0] >= 0:
                if not hash[j - groups[g][i][0]] :
                    continue
                new_val = dp[j - groups[g][i][0]] + groups[g][i][1] * groups[g][i][0]
                if new_val > dp[j]:
                    hash[j] = True
                    dp[j] = new_val
print(dp[-1])