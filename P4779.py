import heapq
import sys
from typing import List
input = sys.stdin.readline
n , m , s = list(map(int,input().split()))
groups = [[] for _ in range(n + 1)]
for i in range(m):
    u , v , w = list(map(int,input().split()))
    groups[u].append((w,v))

def dijkstra(start : int)->List:
    pq = []
    heapq.heappush(pq,(0,start))
    dist = [0x3f3f3f3f for _ in range(n + 1)]
    vis = [False for _ in range(n + 1)]
    dist[start] = 0
    while pq:
        w , v = heapq.heappop(pq)
        if vis[v]:
            continue
        vis[v] = True
        for val in groups[v]:
            if dist[val[1]] > dist[v] + val[0]:
                dist[val[1]]  = dist[v] + val[0]
                heapq.heappush(pq,(dist[val[1]],val[1]))
    return dist
ans = dijkstra(s)
for i in range(1,n + 1):
    print(ans[i],"",end="")
print()