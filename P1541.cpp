#include <iostream>
#include <vector>
static int dp[41][41][41][41];
// 输入数据保证到达终点时刚好用光 M 张爬行卡片。
int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n , m;
    std::cin >> n >> m;
    std::vector<int> score(n);
    for(int i = 0;i < n;i++) std::cin >> score[i];
    std::vector<int> card(5,0);
    for(int i = 0;i < m;i++){
        int temp;
        std::cin >> temp;
        card[temp] ++;
    }
    dp[0][0][0][0] = score[0];
    for(int i = 0;i <= card[1];i++){
        for(int j = 0;j <= card[2];j++){
            for(int k = 0;k <= card[3];k++){
                for(int l = 0;l <= card[4];l++){
                    int curIndex = i + j * 2 + k * 3 + l * 4;
                    if(i < card[1])
                        dp[i + 1][j][k][l] = std::max(dp[i + 1][j][k][l],dp[i][j][k][l] + score[curIndex + 1]);
                    if(j < card[2])
                        dp[i][j + 1][k][l] = std::max(dp[i][j + 1][k][l],dp[i][j][k][l] + score[curIndex + 2]);
                    if(k < card[3])
                        dp[i][j][k + 1][l] = std::max(dp[i][j][k + 1][l],dp[i][j][k][l] + score[curIndex + 3]);
                    if(l < card[4])
                        dp[i][j][k][l + 1] = std::max(dp[i][j][k][l + 1],dp[i][j][k][l] + score[curIndex + 4]);
                }
            }
        }
    }

    std::cout << dp[card[1]][card[2]][card[3]][card[4]] << std::endl;

    return 0;
}