#include <bits/stdc++.h>
using namespace std;
class Solution {
    public: 
        void dfs(const string& digits,int index,string& rom,vector<string>& res,const vector<string>& hash)
        {
            if(index == digits.size())
            {
                res.push_back(rom);
                return;
            }
            for(char c:hash[digits[index] - '0'])
            {
                rom.push_back(c);
                dfs(digits,index+1,rom,res,hash);
                rom.pop_back();
            }
        } 
        vector<string> letterCombinations(string digits) {
            vector<string> hash = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
            vector<string> res;
            string rom;
            if(digits.empty()) return res;
            dfs(digits,0,rom,res,hash);
            return res;
        }
    };