from typing import List
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        rows = len(matrix)
        cols = len(matrix[0])
        hash = [[val for val in matrix[idx]] for idx in range(rows)]
        def dfs(hash,matrix,rows,cols):
            for i in range(rows):
                for j in range(cols):
                    if not hash[i][j] and not matrix[i][j]:
                        for idx in range(rows):
                            matrix[idx][j] = 0
                        for idx in range(cols):
                            matrix[i][idx] = 0

        dfs(hash,matrix,rows,cols)