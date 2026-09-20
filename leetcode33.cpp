#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n = nums.size();
            if(n == 1)   return nums[0] == target ? 0 : -1;
            int left = 0,right = n - 1;
            while(left <= right)
            {
                int mid = (left + right) >> 1;
                if(nums[mid] == target) return mid;
                if(nums[left] <= nums[mid]) //这里取等号是因为，可能存在left == mid 的情况，然后死循环
                {
                    if(nums[left] <= target and nums[mid] > target) right = mid - 1;
                    else left = mid + 1;
                }
                else //nums[left] > nums[mid]
                {
                    if(nums[mid] < target and target < nums[left]) left = mid + 1;
                    else right = mid - 1;
                }
            } 
            return -1;
        }
    };