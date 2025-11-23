#include <vector>
#include <unordered_map>
#include <iostream>
using std::vector;
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int res = 0;
        for(int i = 0;i < nums.size() - 1;i++)
            for(int j = i + 1;j < nums.size();j++)
                res = std::max(res,function(nums,nums[j] - nums[i]));
        return res;
    }
    int function(std::vector<int>& nums,int diff){
        if(vis.count(diff)) return vis[diff];
        int res = 0;
        std::unordered_map<int,int> dp;
        dp[nums.front()] = 1;
        for(int i = 1;i < nums.size();i++){
            int pre = nums[i] - diff;
            dp[nums[i]] = std::max(dp[nums[i]],dp[pre] + 1);
        }
        for(std::unordered_map<int,int>::iterator it = dp.begin();it != dp.end();it++) res = std::max(res,(*it).second);
        vis[diff] = res;
        return res;
    }
private:
    std::unordered_map<int,int> vis;
};
