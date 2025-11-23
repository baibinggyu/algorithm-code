#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int count = 0;
        int dx[4] = {0,-1,0,1};
        int dy[4] = {1,0,-1,0};
        pair<int,int> findMap(const vector<vector<char>>& grid)
        {
            int line = grid.size() , row = grid[0].size();
            for(int i = 0;i < line;++i)
                for(int j = 0;j < row;++j)
                    if(grid[i][j] == '1')
                    {
                        ++count;
                        return {i,j};
                    }
            return {-1,-1};
        }
        void dfs(int x,int y,vector<vector<char>>& grid)
        {
            grid[x][y] = '2';
            for(int i = 0;i < 4;i++)
            {
                int newX = x + dx[i],newY = y + dy[i];
                if(newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY] != '2')
                    if(grid[newX][newY] == '0') grid[newX][newY] = '2';
                    else if (grid[newX][newY] == '1') dfs(newX,newY,grid);
            }
        }
        int numIslands(vector<vector<char>>& grid) {
            pair<int,int> isStop;
            do{
                isStop = findMap(grid);
                if(isStop.first != -1)
                    dfs(isStop.first,isStop.second,grid);
                else break;
            }while(true);
            return count;
        }
    };