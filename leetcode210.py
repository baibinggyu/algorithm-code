from typing import List
import collections
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        inDegree = [0] * numCourses
        for val in prerequisites:
            inDegree[val[0]] += 1
        graph = [[] for _ in range(numCourses)]
        for val in prerequisites:
            graph[val[1]].append(val[0])
        dq = collections.deque([i for i in range(numCourses) if inDegree[i] == 0])
        ret = []
        while len(dq):
            src = dq.popleft()
            ret.append(src)
            for val in graph[src]:
                inDegree[val] -= 1
                if inDegree[val] == 0:
                    dq.appendleft(val)
        return ret if len(ret) == numCourses else []