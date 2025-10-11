#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using std::string;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        std::vector<std::vector<int>> dp(text2.size(),std::vector<int>(text1.size(),0));
        for(int i = 0;i < text1.size();i++) if(text2.front() == text1[i]){std::fill(dp[0].begin() + i,dp[0].end(),1);break;}
        for(int i = 0;i < text2.size();i++) if(text1.front() == text2[i]){
            for(int j = i;j < dp.size();j++)
                dp[j][0] = 1;
            break;
        }
        for(int i = 1;i < text2.size();i++){
            for(int j = 1;j < text1.size();j++){
                if(text2[i] == text1[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else{
                    dp[i][j] = std::max({dp[i][j - 1],dp[i - 1][j]});
                }
            }
        }
        return (dp.back()).back();
    }
};
