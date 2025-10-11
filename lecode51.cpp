#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<string>> res;
        bool check(int row,int col,vector<string>& form)
        {
            int n = form.size();
            for(int i = 0;i < n;i++)
                if(form[row][i] == 'Q') return false;
            for(int i = 0;i < n;i++)
                if(form[i][col] == 'Q') return false;
            for(int i = row + 1,j = col - 1;i < n && j > -1;i++,j--)
                if(form[i][j] == 'Q') return false;
            for(int i = row - 1,j = col + 1;i > -1 && j < n;i--,j++)
                if(form[i][j] == 'Q') return false;
            for(int i = row - 1,j = col - 1; i > -1 && j > -1;i--,j--)
                if(form[i][j] == 'Q') return false;
            for(int i = row + 1,j = col + 1;i < n && j < n;i++,j++)
                if(form[i][j] == 'Q') return false;
            return true;
        }
        void bfs(vector<string>& form,int cnt,int row)
        {   
            int n = form.size();
            if(cnt == n) {
                res.push_back(form);
                return ;
            }
            for(int i = 0;i < n;i++)
            {
                if(form[row][i] == '.' && check(row,i,form))
                {
                    form[row][i] = 'Q';
                    bfs(form,cnt + 1,row  + 1);
                    form[row][i] = '.';
                }
            }

        }
        vector<vector<string>> solveNQueens(int n) {
            vector<string> form(n,string(n,'.'));
            bfs(form,0,0);
            return res;
        }
    };