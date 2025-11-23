#include <vector>
#include <algorithm>
#include <iostream>
constexpr int INF = 0x3f3f3f3f;
using std::vector;
void print(std::vector<int>& dp){std::for_each(std::begin(dp),std::end(dp),[](auto& x){std::cout << x << ' ';});std::cout << std::endl;};
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        if(prices.size() == 1) return prices.front();
        if(prices.size() == 2) return prices.front();
        std::vector<int> dp(prices.size() + 1,INF);
        dp[0] = 0;
        dp[1] = prices.front();
        dp[2] = prices[0];
        dp[3] = std::min(prices[0] + prices[1],prices[0] + prices[2]);
        // print(dp);
        for(int i = 2;i < static_cast<int>(dp.size());i++){
            int idx = i - 1;
            int temp01 = dp[i - 1] + prices[idx];
            int temp02 = dp[i] + prices[idx];
            for(int j = i;j <= i + i and j < static_cast<int>(dp.size());j++) dp[j] = std::min({dp[j],temp01,temp02});
            // print(dp);
        }        
        return dp.back();
    }
};