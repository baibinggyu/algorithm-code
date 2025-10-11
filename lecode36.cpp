#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            vector<vector<int>> col(9,vector<int>(10,0));
            vector<vector<int>> row(9,vector<int>(10,0));
            for(int i = 0;i < 9;i++)
            {
                for(int j = 0;j < 9;j++)
                {
                    if(board[i][j] != '.')
                        if(++col[i][board[i][j] - '0'] == 2)
                            return false;
                    
                    if(board[j][i] != '.')
                        if(++row[i][board[j][i] - '0'] == 2)
                            return false;
                }
            } 
            for(int i = 0;i < 9;i += 3)
            {
                for(int j = 0;j < 9;j += 3)
                {
                    vector<int> hash(10,0);
                    for(int m = i;m < i + 3;m++)
                        for(int n = j;n < j + 3;n++)
                            if(board[m][n] != '.')
                                if(++hash[board[m][n] - '0'] == 2)
                                    return false;
                }
            }
           return true;
        }
    };