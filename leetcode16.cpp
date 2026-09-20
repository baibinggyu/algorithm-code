#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool cmpMin(int a,int b){return a < b? a:b;}
        int threeSumClosest(vector<int>& nums, int target) {
            int left=  0,right = nums.size() - 1;
            int res = INT_MAX;
            sort(nums.begin(),nums.end());
            while(left < right )
            {
                int l = left + 1,r  = right;
                if(left > 0 && nums[left] == nums[left-1]) {left++;continue;}
                while(l < r)
                {
                    int sum = nums[left] + nums[l] + nums[r];
                    res = abs(res) > abs(sum - target)? sum - target:res;
                    if(sum > target) r--;
                    else if (sum < target) l++;
                    else if (sum == target) return target;
                }
                left++;
            }
            return res + target;
        }
    };
//-4,-1,1,2