#include <iostream>
#include <vector>
#include <algorithm>
constexpr int N = 4 * (1e2 + 5);
int arr[N],pre[N],dpMin[N][N],dpMax[N][N];
int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n ;std::cin >> n;
    if(n == 1) return std::cin >> n,std::cout << n << std::endl << n << std::endl,0;
    for(int i = 1;i <= n;i++) std::cin >> arr[i],arr[i + n] = arr[i];
    for(int i = 1;i <= (n << 1);i++) pre[i] = pre[i - 1] + arr[i];
    for(int i = 1;i <= (n << 1);i++) {for(int j = 1;j <= (n << 1);j++) dpMin[i][j] = 0x3f3f3f3f,dpMax[i][j] = 0;dpMin[i][i] = dpMax[i][i] = 0;}
    for(int start = 1;start <= n;start++){
        int end = start + n;
        for(int len = 2;len <= n;len++){
           for(int i = start;i + len - 1 < end;i++){
                int j = i + len - 1;
                for(int k = i;k < j;k++){
                    dpMax[i][j] = std::max(dpMax[i][k] + dpMax[k + 1][j] + pre[j] - pre[i - 1],dpMax[i][j]);
                    dpMin[i][j] = std::min(dpMin[i][k] + dpMin[k + 1][j] + pre[j] - pre[i - 1],dpMin[i][j]);
                }
           }
        }
    }
    int resMax = 0 , resMin = 0x3f3f3f3f;
    for(int i = 1;i <= n;i++) resMax = std::max(resMax,dpMax[i][i + n - 1]),resMin = std::min(resMin,dpMin[i][i + n - 1]);
    std::cout << resMin << std::endl << resMax << std::endl;
    return 0;
}