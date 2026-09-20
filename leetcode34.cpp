#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> searchRange(vector<int>& nums, int target) {
            if(nums.empty()) return {-1,-1};
            int left = -1,right = -1;
            int l = 0,r = nums.size() - 1;
            while(l < r)
            {
                int mid = (l + r) >> 1;
                if(nums[mid] < target)  l = mid + 1;
                else r = mid;
            }
            left = nums[l] == target ? l : -1;
            
            l = 0 , r = nums.size() - 1;
            while(l < r)
            {
                int mid = (l + r + 1) >> 1;
                if( nums[mid] > target) r = mid - 1;
                else l = mid;
            }
            right = nums[r] == target ? r : -1;
            return {left,right};
        }
    };  