#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using std::vector;
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        if(nums.size() == 1) return nums.front();
        std::deque<int> dq;
        dq.push_back(0) ;
        std::vector<int> dp(nums.size());
        dp.front() = nums.front();
        for(int i = 1;i < static_cast<int>(nums.size());i++){
            while(not dq.empty() and dq.front() < i - k) dq.pop_front();
            dp[i] = dp[dq.front()] + nums[i];
            while(not dq.empty() and dp[dq.back()] <= dp[i])dq.pop_back();
            dq.push_back(i);
        }
        return dp.back();
    }   
};  