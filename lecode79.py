import collections
from typing import List
class Solution:
    def dfs(self,board:List[List[str]],word:str,visited:dict,matchIndex:int,edge:List,x:int,y:int)->bool:
            if matchIndex == len(word):
                 return True
            if x < edge[0] or y < edge[1] or x >= edge[2] or y >= edge[3]:
                 return False
            if visited[y][x]:
                 return False
            if board[y][x] != word[matchIndex]:
                 return False
            visited[y][x] = True
            if self.dfs(board,word,visited,matchIndex + 1,edge,x,y - 1):
                 return True
            if self.dfs(board,word,visited,matchIndex + 1,edge,x - 1,y):
                 return True
            if self.dfs(board,word,visited,matchIndex + 1,edge,x,y + 1):
                 return True
            if self.dfs(board,word,visited,matchIndex + 1,edge,x + 1,y):
                 return True
            visited[y][x] = False 
            return False
    def exist(self, board: List[List[str]], word: str) -> bool:
        edge = [0,0,len(board[0]),len(board)]
        visited = {i:{j:0 for j in range(len(board[0]))} for i in range(len(board))}
        for i in range(len(board)):
             for j in range(len(board[0])):
                  if self.dfs(board,word,visited,0,edge,j,i):
                       return True
        return False

            