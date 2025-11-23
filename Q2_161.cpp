#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int x,int y){
        return x >= 0 && y >= 0 && x <= ex && y <= ey;
    }
    void dfs(vector<vector<bool>>& vis,int x,int y,int& sum){
        if(!check(x,y)){
            return;
        }
        if(vis[x][y]) {
            return;
        }
        if(!gmap[x][y]){
            vis[x][y] = true;
            return;
        }
        vis[x][y] = true;
        sum += gmap[x][y];
        dfs(vis,x-1,y,sum);
        dfs(vis,x,y-1,sum);
        dfs(vis,x+1,y,sum);
        dfs(vis,x,y+1,sum);
    
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        gmap = grid;
        int n = grid.size();
        int m = grid[0].size();
        ex = n - 1,ey = m - 1;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(vis[i][j]) continue;
                if(grid[i][j]){
                    int sum = 0;
                    dfs(vis,i,j,sum);
                    if(sum != 0 && sum % k == 0) res ++;
                }else vis[i][j] = true;
            }
        }
        return res;
    }       
private:
    vector<vector<int>> gmap;
    int res = 0;
    int ex,ey;
};