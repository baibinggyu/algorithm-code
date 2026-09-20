#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        std::vector<std::vector<int>> dp(nums1.size(),std::vector<int>(nums2.size(),0));
        for(int i = 0;i < nums1.size();i++){
            if(nums1[i] == nums2.front()){
                for(int j = i;j < nums1.size();j++)
                    dp[j][0] = 1;
                break;
            }
        } 
        for(int i = 0 ;i < nums2.size();i++) if(nums2[i] == nums1.front()) std::fill(dp[0].begin() + i,dp[0].end(),1);
        
        for(int i = 1;i < dp.size();i++){
            for(int j = 1;j < dp[i].size();j++){
                if(nums1[i] == nums2[j]){
                    dp[i][j] = std::max(dp[i][j - 1],dp[i - 1][j - 1] + 1);
                }else{
                    dp[i][j] = std::max({dp[i - 1][j - 1],dp[i][j - 1],dp[i - 1][j]});
                }
            }
        }  
        return (dp.back()).back();
    }
};