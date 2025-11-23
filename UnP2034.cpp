#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>
#define int long long
signed main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n , k ;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    std::for_each(arr.begin(),arr.end(),[](auto& x){std::cin >> x;});
    long long res = std::accumulate(arr.begin(),arr.end(),0ll);
    std::deque<int> dq;
    std::vector<int> dp(n);
    dp[0] = arr[0];
    dq.push_back(0);
    for(int i = 1;i < n;i++){
        dp[i] = dp[dq.front()] + arr[i];
        while(!dq.empty() and dp[dq.back()] >= dp[i]) dq.pop_back();
        dq.push_back(i);
        while(!dq.empty() and dq.front() < i - k) dq.pop_front();
    }
    std::for_each(dp.begin(),dp.end(),[](auto& x){std::cout << x << ' ';});
    std::cout << std::endl;
    return std::cout << res - *std::min_element(dp.begin() + n - k ,dp.end()) << std::endl,0;
}