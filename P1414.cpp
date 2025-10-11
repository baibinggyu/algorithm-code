#include <iostream>
#include <vector>
#include <algorithm>
constexpr int SIZE = 1e6 + 5;
int cnt[SIZE];
int freq[SIZE];
int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int mx = -1;
    for(int i = 0;i < n;i++){
        int temp;
        std::cin >> temp;
        cnt[temp] ++;
        mx = std::max(mx,temp);
    }

    for(int i = mx;i >= 1;i--){
        for(int j = i;j <= mx; j += i){
            freq[i] += cnt[j];
        }
    }
    
    std::vector<int> res(n + 1,0);
    for(int i = 1;i <= mx;i++){
        int x = freq[i];
        if(x) res[x] = std::max(res[x],i); 
    }
    for(int i = n - 1;i >= 1;i--){
        res[i] = std::max(res[i],res[i + 1]);
    }
    for(int i = 1;i < (int)res.size();i++) {
        if (res[i] == 0 ) std::cout << "1" << std::endl;
        else std::cout << res[i] << std::endl;
    }
    return 0;
}