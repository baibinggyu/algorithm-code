import sys
sys.setrecursionlimit(200000)

n = int(input())
next = [0 for i in range(n + 1)]
for i in range(1,n + 1):
    next[i] = int(input())
vis = [False for _ in range(n + 1)]
ans = [0 for _ in range(n + 1)]
def dfs(cur : int):
    if ans[cur]:
        return
    if vis[cur]:
        circle = 1
        j = next[cur]
        while j != cur:
            circle += 1
            j = next[j]
        j = cur
        while True:
            ans[j] = circle
            j = next[j]
            if j == cur:
                break
        return
    vis[cur] = True
    dfs(next[cur])
    if not ans[cur]:
        ans[cur] = ans[next[cur]] + 1
for i in range(1,n + 1):
    dfs(i)
for i in range(1,len(ans)):
    print(ans[i])
    