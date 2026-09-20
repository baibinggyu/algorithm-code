#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        std::vector<int> dp(nums.size());
        std::fill(dp.begin(),dp.end(),1);
        std::vector<int> cnt(nums.size());
        std::fill(cnt.begin(),cnt.end(),0);
        *cnt.begin() = 1;
        for(int i = 1;i < nums.size();i++)
            for(int j = 0;j < i;j++)
                if(nums[i] > nums[j])
                    dp[i] = std::max(dp[i],dp[j] + 1);
        
        int mxl = *std::max_element(dp.begin(),dp.end());
        
        for(int i = 1;i < cnt.size();i++){
            bool flag = true;
            for(int j = 0;j < i;j++)
                if(nums[i] > nums[j] and dp[i] == dp[j] + 1){
                    cnt[i] += cnt[j];
                    flag = false;
                }
            if(flag) cnt[i] = 1;
        }
            

        int res = 0;
        for(int i = 0;i < dp.size();i++)
            if(dp[i] == mxl) res += cnt[i];
        return res;
    }
};
