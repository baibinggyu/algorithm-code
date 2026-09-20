#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int res = 0;
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
        void bfs(vector<string> hash,int row,int cnt)
        {
            int n = hash.size();
            if(cnt == n) {res++;return;}
            for(int i = 0;i < n;i++)
            {
                if(hash[row][i] == '.' && check(row,i,hash))
                {
                    hash[row][i] = 'Q';
                    bfs(hash,row + 1,cnt + 1);
                    hash[row][i] = '.';
                }
            }
        }
        int totalNQueens(int n) {
            vector<string> hash(n,string(n,'.'));
            bfs(hash,0,0);
            return res;
        }
    };