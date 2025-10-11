#include <bits/stdc++.h>
int main(void){
    int n,M,T;
    std::cin >> n >> M >> T;
    std::vector<std::vector<int>> arr(n,std::vector<int>(2)); // 金钱 时间
    for(int i = 0;i < arr.size();i++)
        for(int j = 0;j < arr[i].size();j++) 
            std::cin >> arr[i][j];
    std::vector<std::vector<int>> dp(M + 1,std::vector<int>(T + 1,0));
    for(auto x : arr){
        for(int i = dp.size() - 1;i > 0;i--)
            for(int j = dp[i].size();j > 0;j--){
                if(i - x[0] < 0 || j - x[1] < 0) break;
                dp[i][j] = std::max(dp[i - x[0]][j - x[1]] + 1,dp[i][j]); 
            }
                
    }
    std::cout << (dp.back()).back() << std::endl;

    return 0;
}