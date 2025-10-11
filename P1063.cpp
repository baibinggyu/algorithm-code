#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
// void Print(std::vector<std::vector<int>> &dp);
int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    std::for_each(arr.begin(),arr.end(),[](auto& x){std::cin >> x;});
    std::vector<std::pair<int,int>> a(n << 1);
    for(int i = 0;i < static_cast<int>(a.size());i++){
        a[i].first = arr[i % n];
        a[i].second = arr[(i + 1) % n];
    }

    // std::for_each(a.begin(),a.end(),[](auto& x){std::cout << x.first << ' ' << x.second << ' ' ;}),std::cout << std::endl;

    std::vector<std::vector<int>> dp(n << 1,std::vector<int>(n << 1,0));
    for(int len = 2;len <= n;len++){
        for(int start = 0;start + len - 1 < static_cast<int>(dp.size());start++){
            int end = start + len - 1;
            for(int i = start;i < end;i++){
                dp[start][end] = std::max(dp[start][end],dp[start][i] + dp[i + 1][end] + (a[start].first * a[i].second * a[end].second));
            }
        }
    }

   int ans = 0;
   for(int i = 0;i < n;i++) ans = std::max(ans,dp[i][i + n - 1]);
   std::cout << ans << std::endl;
    return 0;
}
// void Print(std::vector<std::vector<int>> &dp){
//     for(int i = 0;i < static_cast<int>(dp.size());i++)
//         std::for_each(dp[i].begin(),dp[i].end(),[](auto& x){std::cout << x << ' ' ;}),std::cout << std::endl;
// }