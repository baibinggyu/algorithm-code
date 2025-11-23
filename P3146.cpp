#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    int n;std::cin >> n;
    std::vector<int> arr(n);
    std::for_each(arr.begin(),arr.end(),[](auto& x){std::cin >> x;});
    std::vector<std::vector<int>> dp(n,std::vector<int>(n,0));
    int ans = 0;
    for(int i = 0;i < n;i++) dp[i][i] = arr[i],ans = std::max(ans,arr[i]);
    for(int len = 2;len <= n;len++){
        for(int i = 0;i + len - 1 < n;i++){
            int j = i + len - 1;
            for(int k = i;k < j;k++){
                if(dp[i][k] && dp[k + 1][j] and (dp[i][k] == dp[k + 1][j])) dp[i][j] = std::max(dp[i][k] + 1,dp[i][j]),ans = std::max(ans,dp[i][j]);
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;   
}