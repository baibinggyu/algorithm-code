#include <vector>
#include <iostream>
#include <algorithm>
#define int long long 
int n;
constexpr int N = 1e6 + 5;
int arr[N];

signed main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for(int i = 1;i <= n;i++) std::cin >> arr[i];
    std::vector<int> dpL(n + 1,0),dpR(n + 1,0);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j < i;j++){
            dpL[i] = std::max(dpL[i],(i - j) * std::min(arr[i],arr[j]));
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = i; j <= n;j++){
            dpR[i] = std::max(dpR[i],(j - i) * std::min(arr[j],arr[i]));
        }
    }
    int res = 0;
    for(int i = 2;i < n;i++) res = std::max(res,dpL[i] + dpR[i]);
    std::cout << res << std::endl;
    return 0;
}