#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int __int128_t
__int128_t POW(long n){
    __int128 ret = 1;
    for(long i = 0;i < n;i++) ret *= 2;
    return ret;
}
void print(__int128 x){
    if(x == 0){std::cout << 0 << std::endl;return;}
    std::string s;
    while(x){
        s.push_back('0' + x % 10);
        x /= 10;
    }
    std::reverse(std::begin(s),std::end(s));
    std::cout << s << std::endl;
}
signed main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long n , m;
    std::cin >> n >> m;
    std::vector<std::vector<long>> arr(n,std::vector<long>(m));
    for(int i = 0;i < n;i++) std::for_each(arr[i].begin(),arr[i].end(),[](auto& x){std::cin >> x;});
    int ans = 0;
    if(m == 1){
        for(int i = 0;i < n;i++) ans += arr[i].front();
        return print(ans),0;
    }
// 每行取数的得分之和，每行取数的得分 = 被取走的元素值 ×2 i,其中 i 表示第 i 次取数（从 1 开始编号）
    for(int row = 0;row < n;row++){
        std::vector<std::vector<int>> dp(m,std::vector<int>(m,0));
        for(int i = 0;i < m;i++) dp[i][i] = arr[row][i] * POW(m);
        for(int len = 2;len <= m;len++){
            for(int start = 0;start + len - 1 < m;start++){
                int end = start + len - 1;
                int step = m - len + 1;
                dp[start][end] = std::max(dp[start + 1][end] + arr[row][start] * POW(step),dp[start][end - 1] + arr[row][end] * POW(step));
            }
        }
        ans += dp[0][m - 1];        
    }
    return print(ans),0;
}