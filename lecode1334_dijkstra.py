from typing import List
import heapq
class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        graph = [[] for _ in range(n)]
        for u , v , w in edges:
            graph[u].append((v,w))
            graph[v].append((u,w))

        def dijkstra(start : int):
            dist = [0x3f3f3f3f] * n
            dist [start] = 0 
            heap = [(0,start)]
            while heap:
                d , u = heapq.heappop(heap)
                if d > dist[u]:
                    continue
                for v , w in graph[u]:
                    if dist[v] > dist[u] + w:
                        dist[v] = dist[u] + w
                        heapq.heappush(heap,(dist[u],v))
            count = sum(1 for x in dist if x <= distanceThreshold)
            return count
        res = [0] * n
        ret = n - 1
        for i in range(n - 1,-1,-1):
            cnt = dijkstra(i)
            res[i] = cnt
            if res[ret] > res[i]:
                ret = i
        return ret
