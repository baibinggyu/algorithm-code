#include <iostream>
#include <algorithm>
#include <vector>
int moneyCount(std::vector<int>& arr){
    int res = 0;
    std::sort(arr.begin(),arr.end());
    std::vector<bool> dp(arr.back() + 1,false);
    dp[0] = true;
    for(auto x : arr){
        if(dp[x]) continue;
        res ++;
        for (int i = 0;i  + x < (int)dp.size();i++){
            int index = i + x;
            if(!dp[i] || index > arr.back()) continue;
            dp[index] = true;
        }
    }
    return res;
}
int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for(int i  = 0;i < (int)arr.size();i++) std::cin >> arr[i];
        std::cout << moneyCount(arr) << std::endl;
    }
    return 0;
}