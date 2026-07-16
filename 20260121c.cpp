#include <iostream>
#include <vector>
signed main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;std::cin >> t;
    while(t--){
        int n;std::cin >> n;
        std::vector<int> arr(n + 1,0);
        std::vector<int> dp(n + 1,0);
        std::vector<std::vector<int>> p(n + 1,std::vector<int>());
        for(int i = 1;i < static_cast<int>(arr.size());i++) std::cin >> arr[i];
        for(int i = 1;i < static_cast<int>(dp.size());i++){
            int x = arr[i];
            p[x].push_back(i);
            int t = p[x].size();
            dp[i] = dp[i - 1];
            if(t >= x) {
                dp[i] = std::max(dp[i],dp[p[x][t - x] - 1] + x);
            }
        }
        std::cout << dp.back() << std::endl;
    }
}
