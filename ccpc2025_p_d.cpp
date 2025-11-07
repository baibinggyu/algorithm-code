#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iomanip>
#define PRE 9
#define int long long
double calc(std::pair<int,int>& a,std::pair<int,int>& b){
    int dx = a.first - b.first,dy = a.second - b.second;
    return ::sqrt(dx * dx + dy * dy);

}
signed main(void){
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    if(n == 1) {
        int temp;
        std::cin >> temp ;
        std::cout << std::fixed << std::setprecision(PRE) << 0.0 << std::endl;
        return 0;
    }
    std::vector<std::pair<int,int>> g(n + 1);
    for(int i = 1;i < n + 1;i++){
        int x, y;
        std::cin >> x >> y;
        g[i].first = x  ,g[i].second = y;
    }
    std::vector<double> dp(n + 1);
    dp[0] = 0,dp[1] = 0;
    dp[2] = ::calc(g[1],g[2]);
    for(int i = 3;i < n + 1;i++){
        for(int j = 1;j <= i;j++)   
            dp[i] = std::max(dp[i],dp[j - 1] + ::calc(g[i],g[j]));
    }
    std::cout << std::fixed << std::setprecision(PRE) << dp.back() << std::endl;
    return 0;
}