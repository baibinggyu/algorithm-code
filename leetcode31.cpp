#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            int n = nums.size();
            if (n == 1) return;
            int flag = 1;
            int i = n - 2;;
            while(~i)
            {
                if(nums[i] <= nums[i+1])
                {
                    for(int j = n - 1;j > i;j--)
                    {
                        if(nums[j] > nums[i])
                        {
                            swap(nums[i],nums[j]);
                            reverse(nums.begin() + i + 1,nums.end());
                            return;
                        }
                    }
                }
                i--;
            }
            if(i == - 1)
            {
                reverse(nums.begin(),nums.end());
                return;
            }
        }
    };