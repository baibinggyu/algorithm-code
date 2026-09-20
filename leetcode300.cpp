#include <vector>
#include <ranges>
#include <algorithm>
using std::vector;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> dp;
        dp.push_back(nums.front());
        for(int i = 1;i < nums.size();i++){
            auto it = std::lower_bound(dp.begin(),dp.end(),nums[i]);
            if(it == dp.end()){
                dp.push_back(nums[i]);
                continue;
            }
            *it = nums[i];
        }    
        return dp.size();
    }
};