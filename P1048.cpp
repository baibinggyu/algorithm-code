#include <iostream>
#include <vector>
int main(void){
    int t,m;
    std::cin >> t >> m;
    std::vector<int> dp(t + 1,0); // value
    std::vector<std::vector<int>> medicine(m,std::vector<int>(2));
    for(int i = 0;i < (int)medicine.size();i++)
        for(int j = 0;j < (int)medicine[0].size();j++)
            std::cin >> medicine[i][j];
    for(int i = medicine.size() - 1;~i;i--){
        for(int j = dp.size();j >= medicine[i][0];j--){
            dp[j] = std::max(dp[j],dp[j - medicine[i][0]] + medicine[i][1]);
        }
    }
    std::cout << dp.back() << std::endl;

    return 0;
}