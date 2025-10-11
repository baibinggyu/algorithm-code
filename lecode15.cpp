#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> res;
            int l,r;
            int left = 0,right = nums.size() - 1;
            sort(nums.begin(),nums.end());
            while(left < right)
            {
                if(nums[left] > 0) break;
                if(left > 0 && nums[left] == nums[left-1]) {left++;continue;}
                int l = left + 1,r = right;
                while(l < r)
                {
                    if(nums[left] + nums[l] + nums[r] > 0) r--;
                    else if(nums[left] + nums[l] + nums[r] < 0) l++;
                    else {
                        res.push_back({nums[left],nums[l],nums[r]});
                        r--,l++;
                        while(l < r && nums[l] == nums[l-1]) l++;
                        while(l < r && nums[r] == nums[r+1]) r--;
                    } 
                    
                }
                left++;
            }   
            
            return res;
        }
    };
    //-4,-1,-1,0,1,2
    //-2,0,1,1,2