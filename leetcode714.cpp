#include <vector>
#include <algorithm>
using std::vector;
class Solution {
public:
    #define OWN 0
    #define UNOWN 1
    int maxProfit(vector<int>& prices, int fee) {
        std::vector<std::vector<int>> dp(prices.size(),std::vector<int>(2));
        dp[0][OWN] = -prices[0],dp[0][UNOWN] = 0;
        for(int i = 1; i < dp.size();i++){
            dp[i][OWN] = std::max(dp[i - 1][OWN],dp[i - 1][UNOWN] - prices[i]);
            dp[i][UNOWN] = std::max(dp[i - 1][OWN] - fee + prices[i],dp[i - 1][UNOWN]);
        }
        return std::max({(dp.back())[OWN],(dp.back())[UNOWN],(dp.back())[OWN] + prices.back() - fee});
    }
};