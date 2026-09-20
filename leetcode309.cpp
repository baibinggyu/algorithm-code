#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
    #define OWN 0
    #define FREE 1
    #define UNOWN 2
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1) return 0;
        std::vector<std::vector<int>> dp(prices.size(),std::vector<int>(3,0));
        dp[0][OWN] = -prices.front(),dp[0][FREE] = 0,dp[0][UNOWN] = 0;
        for(int i = 1;i < dp.size();i++){
            dp[i][OWN] = std::max(dp[i - 1][UNOWN] - prices[i],dp[i - 1][OWN]);
            dp[i][FREE] = dp[i - 1][OWN] + prices[i];
            dp[i][UNOWN] = std::max(dp[i - 1][UNOWN],dp[i-1][FREE]);
        }
        return std::max({(dp.back())[OWN] + prices.back(),(dp.back())[FREE],(dp. back())[UNOWN]});
    }
};