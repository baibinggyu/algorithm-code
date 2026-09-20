#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string convert(string s, int numRows) {
            if(s.size() == 1) return s;
            int count = 0;
            string res;
            vector<vector<char>> str(numRows,vector<char>(0));
            while(count < s.size())
            {
                for(int i = 0;i < numRows && count < s.size();i++) str[i].push_back(s[count++]);
                for(int i = numRows - 2 ;i > 0 && count < s.size();i--) str[i].push_back(s[count++]);
            }
            for(int i = 0;i < numRows;i++)
                for(int j = 0;j < str[i].size();j++)
                    res += str[i][j];
            return res;
        }
    };