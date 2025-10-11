#include <iostream>
#include <vector>
#include <algorithm>
#define R 1000 + 5
// int dp[R][R];

int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int r;
    std::cin >> r;
    std::vector<std::vector<int>> arr(r);
    std::vector<std::vector<int>> dp(r);
 
    for(int i = 0;i < r;i++){   
        int temp;
 
        for(int j = 0;j < i + 1;j++){
            std::cin >> temp;
            arr[i].emplace_back(temp);
            dp[i].emplace_back(0);
        }
    }
     dp[0][0] = arr.front().front();
    for(int i = 1;i < arr.size();i++){
        dp[i][0] = arr[i][0] + dp[i - 1][0];
        dp[i][dp[i].size() - 1] = arr[i].back() + dp[i - 1][dp[i - 1].size() - 1];
    }
 
    for(int i = 2;i < arr.size();i++){
        for(int j = 1;j < arr[i].size();j++){
            dp[i][j] = std::max(dp[i - 1][j],dp[i - 1][j - 1]) + arr[i][j];
        }
    }
     int res = 0;
    for(int i = 0;i < arr.back().size();i++) res = std::max(res,dp[arr.size() - 1][i]);
    std::cout << res <<std::endl;
    return 0;
}