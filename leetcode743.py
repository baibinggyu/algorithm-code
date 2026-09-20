from typing import List
import heapq
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = [[] for _ in range(n + 1)]
        for val in times:
            graph[val[0]].append((val[1],val[2]))
        def dijkstral(start : int) -> int:
            dist = [0x3f3f3f3f for i in range(n + 1)]
            dist[start] = 0
            heap = [(0,start)]
            while heap:
                w , u = heapq.heappop(heap)
                if w > dist[u]:
                    continue
                for val in graph[u]:
                    if dist[val[0]] > dist[u] + val[1]:
                        dist[val[0]] = dist[u] + val[1]
                        heapq.heappush(heap,(dist[val[0]],val[0]))
            for i in range(1,len(dist)):
                if dist[i] ==0x3f3f3f3f:
                    return -1
            return max(dist[1:])
        return dijkstral(k)