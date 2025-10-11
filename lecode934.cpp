#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int dx[4] = {0,-1,0,1};
        int dy[4] = {1,0,-1,0};
        queue<pair<int,int>> q1;
        pair<int,int> findStart(const vector<vector<int>> & grid)
        {
            int n = grid.size();
            for(int i =0;i < n;i++)
                for(int j = 0;j < n;j++)
                    if(grid[i][j] == 1) return {i,j};
            return {-1,-1};
        }
        void dfs(int x,int y,vector<vector<int>> & grid)
        {
            grid[x][y] = 2;
            for(int i = 0;i < 4;i++)
            {   
                int newX = x + dx[i];
                int newY = y+ dy[i];
                if(newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid.size() && grid[newX][newY] != 2 )
                {
                    if(grid[newX][newY] == 0)
                    {
                        grid[newX][newY] = 2;
                        q1.push({newX,newY});
                    }
                    else if (grid[newX][newY] == 1)
                    {
                        dfs(newX,newY,grid);
                        grid[newX][newY] = 2;
                    }
                }
            }
            

        }
        int shortestBridge(vector<vector<int>>& grid) {
            int n = grid.size();
            auto [temp01,temp02] = findStart(grid);
            dfs(temp01,temp02,grid);
            int count = 0;
            while(!q1.empty())
            {
                int size = q1.size();
                while(size--)
                {
                    for(int i = 0;i < 4;i++)
                    {
                        int newX = dx[i] + q1.front().first;
                        int newY = dy[i] + q1.front().second;
                        if(newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid.size() && grid[newX][newY] == 1) return ++count;
                        if(newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid.size() && grid[newX][newY] == 0)
                        {
                            grid[newX][newY] = 3;
                            q1.push({newX,newY});
                        }   
                    }
                    q1.pop();
                }
                count++;
            }
            return -1;
        }
    };