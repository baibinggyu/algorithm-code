#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            if(nums.empty()) return 0;
            int l = 0,r = nums.size() - 1;
            int res = 0;
            while(l <= r)
            {
                if(nums[r] == val) r--;
                else if (nums[l] == val)
                {
                    nums[l] = nums[r];
                    r--,l++;
                    res++;
                }
                else if(nums[l] != val) l++;
            }
            return l;
        }
    };