#include <iostream>
#include <vector>
#define int  unsigned long long
signed main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    std::vector<unsigned long long> out;
    while (T--){
        int n,m,q;
        std::cin >> n >> m >> q;
        std::vector<std::vector<int>> data(n,std::vector<int>(m));
        for (int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                std::cin >> data[i][j];
        std::vector<std::vector<int>> dp(n,std::vector<int>(m));
        dp[0][0] = data[0][0];
        //  row
        for (int i = 1;i < n;i++) dp[i][0] = dp[i - 1][0] + data[i][0];
        //  col
        for (int j = 1;j < m;j++) dp[0][j] = dp[0][j - 1] + data[0][j];
        
        for(int i = 1;i < n;i++)
            for(int j = 1;j < m;j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + data[i][j];
        unsigned long long res = 0;
        for (int i = 0;i < q;i++){
            int u,v,x,y;
            std::cin >> u >> v >> x >> y;
            u--,v--,x--,y--;
            int temp = dp[x][y];
            if(u  >= 1) temp -= dp[u - 1][y];
            if(v  >= 1) temp -= dp[x][v - 1];
            if(u >= 1 && v  >= 1) temp += dp[u - 1][v - 1];
            res ^= temp;
        }
        out.push_back(res);
        }
        
    for (unsigned long long val : out)
        std::cout << val << std::endl;
    return 0;
}