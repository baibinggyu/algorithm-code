#include <iostream>
#include <vector>
int main(void){
    int n,m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> arr(m,std::vector<int>(2));
    for(int i = 0;i < arr.size();i++)
        for(int j = 0;j < arr[i].size();j++)
            std::cin >> arr[i][j];
    std::vector<int> dp(n + 1,0);
    for(auto x : arr){
        for(int i = dp.size() - 1;~i;i--){
            int index = i - x[0];
            if(index >= 0)
                dp[i] = std::max(dp[i],dp[index] + x[0] * x[1]);
        }
    }
    std::cout << dp.back() << std::endl;
    return 0;
}