#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int left = 0,right = nums.size() - 1;
            vector<vector<int>> res;
            if(right < 3)  return res;
            sort(nums.begin(),nums.end());
            while(left < right - 2)
            {
                if(left and nums[left] == nums[left - 1]) {left++;continue;}
                int L = left + 1;
                while(L < right - 1)
                {
                    if(L != left + 1 and nums[L] == nums[L-1]){L++;continue;}
                    int l = L + 1,r = right;
                    while(l < r)
                    {
                        long long sum = 1LL * nums[left] + nums[L] + nums[l] + nums[r];//防止溢出
                        if(sum == target)
                        {
                            res.push_back({nums[left],nums[L],nums[l],nums[r]});
                            l++,r--;
                            while(l < r and nums[l] == nums[l-1]) l++;
                            while(l < r and nums[r] == nums[r+1]) r--;
                        }
                        else if(sum < target) l++;
                        else if(sum > target) r--;
                    }
                    L++;
                }
                left++;

            }
            return res;
        }
    };
        
//[-2,-1,-1,1,1,2,2]