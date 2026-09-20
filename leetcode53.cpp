#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];
            int res = INT_MIN;
            vector<int> dp(n,INT_MIN);
            dp[0] = nums[0];
            for(int i = 1;i < n;++i)
            {
                dp[i] = max(nums[i],dp[i-1] + nums[i]);
            }
            for(int temp : dp) 
                res = max(res,temp);
            return res;
        }
    };