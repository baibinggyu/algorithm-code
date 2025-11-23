from typing import List
from collections import deque

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        inDegree = [0] * numCourses
        for val in prerequisites:
            inDegree[val[1]] += 1
        dq = deque([ i for i in range(numCourses) if inDegree[i] == 0])
        graph = [[] for _ in range(numCourses)]
        for val in prerequisites:
            graph[val[0]].append(val[1])        
        ret = []
        while len(dq):
            src = dq.popleft()
            ret.append(src)
            for val in graph[src]:
                inDegree[val] -= 1
                if (inDegree[val] == 0):
                    dq.append(val)
        return False if len(ret) != numCourses else True