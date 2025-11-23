import sys
import collections
input = sys.stdin.readline
n = int(input())
arr = list(map(str,input().split()))
ans = 0
cnt = [0] * 6
for s in arr:
    if s.count('6') >= 6 :
        ans += 1
    else:
        cnt[s.count('6')] += 1

for i in range(1,6):
    for j in range(i,6):
        if i + j >= 6:
            if i == j:
               m = cnt[i] // 2
               cnt[i] -= m * 2
               ans += m
            else:
                m = min(cnt[i],cnt[j])
                ans += m
                cnt[i] -= m
                cnt[j] -= m



for i in range(1,6):
    for j in range(i,6):
        for k in range(j,6):
            if i + j + k >= 6:
                if i == j == k:
                    if cnt[i] >= 3:
                        m = cnt[i] // 3
                        cnt[i] -= m * 3
                        ans += m
                elif i == j:
                    if cnt[i] >= 2:
                        m = min(cnt[i] // 2,cnt[k])
                        ans += m
                        cnt[i] -= m * 2
                        cnt[k] -= m
                elif i == k:
                    if cnt[i] >= 2:
                        m = min(cnt[i] // 2,cnt[j])
                        ans += m
                        cnt[i] -= m * 2
                        cnt[j] -= m
                elif j == k:
                    if cnt[j] >= 2:
                        m = min(cnt[j] // 2,cnt[i])
                        ans += m
                        cnt[j] -= m * 2
                        cnt[i] -= m
                else:
                    m = min(cnt[i],cnt[j],cnt[k])
                    ans += m
                    cnt[i] -= m
                    cnt[j] -= m
                    cnt[k] -= m
print(ans)