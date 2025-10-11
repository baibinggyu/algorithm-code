#include <bits/stdc++.h>
using namespace std;
#define ROW 9
#define COL 9
class Solution {
    public:
    bool isValid(int row,int col,char target,vector<vector<char>>& board)
    {
       for(int i = 0;i < ROW;i++)
            if(board[row][i] == target) return false;
        for(int i = 0;i < COL;i++)
            if(board[i][col] == target) return false;
        int startRow = row / 3 * 3;
        int startCol = col / 3 * 3;
        for(int i = startRow;i < startRow + 3;i++)
            for(int j = startCol;j < startCol + 3;j++)
                if(board[i][j] == target) return false;
        return true;
    }
    bool bfs(vector<vector<char>>& board)
    {
        for(int i = 0;i < ROW;i++)
        {
            for(int j = 0;j < COL;j++)
            {
                if(board[i][j] != '.') continue;
                for(char ch = '1';ch <= '9';ch++)
                {
                    if(isValid(i,j,ch,board))
                        board[i][j] = ch;
                    else continue;
                    if(bfs(board)) return true;
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }
        void solveSudoku(vector<vector<char>>& board) {
            bfs(board);
        }
    };