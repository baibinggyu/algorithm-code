#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
constexpr int N = 3e6 + 5;

int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n ;
    std::vector<std::pair<int,int>> grass(n);
    for(int i = 0;i < n;i++){
        int a , b;
        std::cin >> a  >> b;
        grass[i] = std::make_pair(a,b);
    }
    std::sort(grass.begin(),grass.end(),[](const std::pair<int,int> &a,const std::pair<int,int> &b) -> bool{return a.second < b.second;});
    std::vector<long long> dp(n + 1,0);
    for(int i = 1;i < dp.size();i++){
        dp[i] = dp[i - 1];
        int l = 0 ,r = grass.size() - 1;
        int pos = -1;
        while(l <= r){
            int mid = l + ((r - l) >> 1);
            if (grass[mid].second < grass[i - 1].first) {pos = mid; l = mid + 1;}
            else r = mid - 1;
        }        
        if(pos != -1){
            dp[i] = std::max(dp[i],dp[pos + 1] + grass[i - 1].second - grass[i - 1].first + 1);
        }else{
            dp[i] = std::max(dp[i],grass[i - 1].second - grass[i - 1].first + 1ll);
        }
        
    }
    std::cout << dp.back() << std::endl;
    return 0;
}