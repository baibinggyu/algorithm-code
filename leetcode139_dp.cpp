#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        dp = vector<bool>(s.size() + 1,0);
        dp[0] = true;
        for (int i = 0;i < s.length();i++){
            if(dp[i]){
                for(auto& str : wordDict){
                    if(i + str.size() <= s.length() && s.substr(i,str.size()) == str){
                        if(i + str.size() == dp.size() - 1) return true;
                        dp[i + str.size()] = true;
                    }
                }
            }
            
        }
        return dp.back();

    }
private:
    vector<bool> dp;
};
