#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using std::vector;
class Solution {
public:
    const int ONE = 1;
    const int WEEK = 7;
    const int MONTH = 30;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        std::vector<int> dp(days.back() + 1,0x3f3f3f3f);
        dp[0] = 0;
        std::unordered_map<int,bool> hash;
        std::for_each(days.begin(),days.end(),[&hash](int val){hash[val] = true;});
        for(int i = 1;i < dp.size();i++){
            if(hash.count(i)){
                if (i - ONE >= 0) dp[i] = std::min(dp[i],dp[i - ONE] + costs[0]);
                if(i - WEEK >= 0) for(int j = i - WEEK;j < i ;j++) dp[i] = std::min(dp[i],dp[j] + costs[1]);
                else for(int j = 0;j < i;j++) dp[i] = std::min(dp[i],dp[j] + costs[1]);
                if(i - MONTH >= 0) for(int j = i - MONTH;j < i;j++) dp[i] = std::min(dp[i],dp[j] + costs[2]);
                else for(int j = 0;j < i;j++) dp[i] = std::min(dp[i],dp[j] + costs[2]);
            }else dp[i] = dp[i - 1];
            
            // Print(dp);
        }
        return dp.back();
    }
    void Print(std::vector<int>& arr){
        std::for_each(arr.begin(),arr.end(),[](int a){std::cout << a << ' ';});
        std::cout << std::endl;
    }

};