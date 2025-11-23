#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
int n , m;
constexpr int MOD = 2;

int main(void){
    std::cin >> n >> m;
    std::vector<int> hill;
    for(int i = 0;i < n;i++){
        int mask = 0;
        std::string str;std::cin >> str;
        for(int j = 0;j < static_cast<int>(str.size());j++) if(str[j] == 'H') mask |= (1 << j);
        hill.emplace_back(mask);
    }
    std::vector<std::vector<std::vector<int>>> dp(2,\
        std::vector<std::vector<int>>(1 << m,std::vector<int>(1 << m,0))\
    );
    std::vector<int> vaild;
    for(int i = 0;i < (1 << m);i++) 
    {
        if(i & (i << 1) or i & (i << 2)) continue;
        vaild.emplace_back(i);
    }
    int ans = 0;
    for(auto x : vaild){
        if(x & hill[0]) continue;
        dp[0][x][0] = __builtin_popcount(x);
        ans = std::max(dp[0][x][0],ans);
    }
    if(n == 1) return std::cout << ans << std::endl,0;
    ans = 0;
    for(auto x : vaild){
        if(x & hill[1]) continue;
        for(auto y : vaild){
            if(y & hill[0]) continue;
            if(x & y) continue;
            dp[1][x][y] =std::max(dp[1][x][y],dp[0][y][0] + __builtin_popcount(x));
            ans = std::max(ans,dp[1][x][y]);
        }            
    }
    if(n == 2) return std::cout << ans << std::endl,0;
    ans = 0;
    for(int i = 2;i < n;i++){
        int lastIndx = i % MOD == 0 ? 1 : 0;
        int curIndex = i % MOD;
        for(auto& x : dp[curIndex]) 
           std::fill(std::begin(x),std::end(x),0);
        for(auto x : vaild){
            if(x & hill[i]) continue;
            for(auto y : vaild){
                if(y & hill[i - 1]) continue;
                if(x & y) continue;
                for(auto z : vaild){
                    if(z & hill[i - 2]) continue;
                    if(x & z) continue;
                    dp[curIndex][x][y] = std::max(dp[curIndex][x][y],dp[lastIndx][y][z] + __builtin_popcount(x));
                    ans = std::max(dp[curIndex][x][y],ans);
                }
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}