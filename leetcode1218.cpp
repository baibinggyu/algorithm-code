#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using std::vector;
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        std::unordered_map<int,int> dp;
        dp[arr.front()] = 1;
        for(int i = 1 ;i < arr.size();i++){
            int pre = arr[i] - difference;
            dp[arr[i]] = std::max(dp[arr[i]],dp[pre] + 1);
        }
        int res = 0;
        for(auto it = dp.begin();it != dp.end();it++) res = std::max(res,(*it).second);
        return res;
    }
};
