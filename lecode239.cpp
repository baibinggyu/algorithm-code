#include <vector>
#include <deque>
using std::vector;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> dq;
        int n = nums.size();
        std::vector<int> res;
        for(int i = 0;i < k;i++){
            while(not dq.empty() and nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        for(int i = k ;i < n;i++){
            while(not dq.empty() and nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            while(not dq.empty() and dq.front() < (i - k + 1)) dq.pop_front();
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};