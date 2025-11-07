#include <iostream>
#include <unordered_map>
#include <vector>

int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n , m;
    std::cin >> n >> m;
    std::unordered_map<int,std::vector<std::vector<int>>> groups;
    for (int i = 1;i < m + 1;i++){
        std::vector<int> arr(2);
        int index;
        std::cin >> arr[0] >> arr[1] >> index;
        arr[1] = arr[0] * arr[1];
        if(!index)groups[i].push_back(arr);
        else groups[index].push_back(arr);
        
    }
    std::vector<int> dp(n + 1,0);
    for (auto& g :groups){
        auto& v = g.second;
        std::vector<std::vector<int>> item; 
        item.push_back(v.front());
        if(v.size() > 1) item.push_back({v[0][0] + v[1][0],v[0][1] + v[1][1]});
        if(v.size() > 2){
            item.push_back({v[0][0] + v[2][0],v[0][1] + v[2][1]});
            item.push_back({v[0][0] + v[1][0] + v[2][0],v[0][1] + v[1][1] + v[2][1]});
        }
        for(auto& x : item){
            for(int i = dp.size() - 1;i >= 0;i--){
                if(i - x[0] >= 0){
                    dp[i] = std::max(dp[i],dp[i - x[0]] + x[1]);
                }
            }
        }
    }
    std::cout << dp.back() << std::endl;
    return 0;
}