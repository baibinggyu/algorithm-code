#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
//[110,243,391,586,368,589,303,717]
// 23
// 303
// 输出0
// 预期4
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        if (nums.empty()) return 0;
        int res = 0;
        for(int i = nums.size() - 1;i >= 0;i--){
            if(nums[i] > b) continue; 
            int r = i;
            while(r >= 0 && nums[r] <= b) r--;
            if (r < 0) break;
            for(int j = r;j  < i;j++){
                std::swap(nums[j], nums[j + 1]);
                res++;
            }
        }
        int l = 0,r = nums.size() - 1,right = nums.size() - 1;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (nums[mid] > b) r = mid - 1,right = mid;
            else l = mid + 1;
        }
        r = right;
        if (nums[r] < b) {
            // 说明比b大的没有
            for(int i = nums.size() - 1;i > 0;i--){
                if(nums[i] >= a) continue;
                int r = i - 1;
                while(r >= 0 && nums[r] < a) r--;
                if(r < 0) break;
                for(int j = r;j < i;j++){
                    std::swap(nums[j], nums[j + 1]);
                    res++;
                }
            }
        }else{
            // 比b大的还是存在的
            for(int i = r - 1;i >= 0;i--){
                if(nums[i] >= a) continue;
                int r = i - 1;
                while(r >= 0 && nums[r] < a) r--;
                if(r < 0) break;
                for(int j = r;j < i;j++){
                    std::swap(nums[j], nums[j + 1]);
                    res++;
                }
            }             
        }
        return res % this->mod;
    }
private:
    static constexpr int mod = int(1e9 + 7);
};