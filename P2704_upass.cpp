#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int n , m;
int main(void){
    std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
    std::cin >> n >> m;
    std::vector<int> hill;
    std::vector<int> vaild;
for(int i = 0;i < (1 << m);i++){
        if(i & (i << 1) || i & (i << 2)) continue;
        vaild.emplace_back(i);        
}
    for(int i = 0;i < n;i++){
        int mask = 0;
        std::string str;
        std::cin >> str;
        for(int j = 0;j < static_cast<int>(str.size());j++)
            if(str[j] == 'H') mask |= (1 << j);
        hill.emplace_back(mask);
    }
    std::vector<std::vector<std::vector<int>>> dp(n,std::vector<std::vector<int>>(1 << m,std::vector<int>(1 << m,0)));
    int ans = 0;
    for(auto x : vaild){
        if(x & hill[0]) continue;
        dp[0][x][0] = __builtin_popcount(x);
        ans = std::max(ans,dp[0][x][0]);         
    }
    if(n == 1) return std::cout << ans << std::endl,0;
    ans = 0;
    for(auto x :vaild){
        if(x & hill[1]) continue;
        for(auto y : vaild){
            if(y & hill[0]) continue;
            if(x & y) continue;
            dp[1][x][y] = __builtin_popcount(x) + dp[0][y][0];
            ans = std::max(ans,dp[1][x][y]);
        }
    }
    if(n == 2) return std::cout << ans << std::endl,0;
    for(int i = 2;i < n;i++){
        for(auto x : vaild){
            if(x & hill[i]) continue;
            for(auto y : vaild){
                if(y & hill[i - 1]) continue;
                if(x & y) continue;
                for(auto z : vaild){
                    if(z & hill[i - 2]) continue;
                    if(x & z) continue;
                    dp[i][x][y] = std::max(dp[i][x][y],dp[i - 1][y][z] + __builtin_popcount(x));
                }
            }
        }
    }
    ans = 0;
    for(auto x : vaild)
        for(auto y : vaild)
            ans = std::max(ans,dp[n - 1][x][y]);
    std::cout << ans << std::endl;
    return 0;
}