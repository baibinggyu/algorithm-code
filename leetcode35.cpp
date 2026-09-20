#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            if(nums.empty()) return 0;
            int index = -1;
            int l = 0,r = nums.size() - 1;
            while(l < r)
            {
                int mid = (l + r) >> 1;
                if(nums[mid] < target) l = mid  + 1;
                else if (nums[mid] > target) r = mid - 1;
                else {index = mid; break;}
            }            
            if(index == -1)
                if(nums[l] < target) index = l + 1;
                else index = l;
            return index;
        }
    };