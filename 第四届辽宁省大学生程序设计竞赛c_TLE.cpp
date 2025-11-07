#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#include <algorithm>
#define int long long 
int n;
std::vector<std::pair<int,int>> g;
std::vector<int> p;
void boom(int cur,std::vector<bool>& isDeath){
    for(int i = 1;i <= n;i++){
        if(isDeath[i]) continue;
        p[i] = p[i] - g[cur].second;
        if(p[i] <= 0){
            isDeath[i] = true;
            boom(i,isDeath);
        }
    }
}
int dfs(int cur,std::vector<bool>& isDeath,int deepth){
    isDeath[cur] = true;
    auto it = std::find(isDeath.begin() + 1,isDeath.end(),false);
    if(it == isDeath.end()) {return deepth - 1;}
    
    std::vector<int> record(p);
    std::vector<bool> recordDeath(isDeath);
    for(int i = 1;i <= n;i++){
        if(isDeath[i]) continue;
        p[i] = p[i] - g[cur].second;
        if(p[i] <= 0) {
            isDeath[i] = true;
            boom(i,isDeath);
        }
    }
    int res = 0x3f3f3f3f;
    for(int i = 1;i <= n;i++){
        if(isDeath[i]) continue;
        res = std::min(res,dfs(i,isDeath,deepth + 1));
    }
    if(res == 0x3f3f3f3f) res = deepth;

    p = record;
    isDeath = recordDeath;
    isDeath[cur] = false;
    return res;
}
signed main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    g.resize(n + 1);
    p.resize(n + 1);
    std::vector<bool> isDeath(n + 1,false);
    for(int i = 1;i < static_cast<int>(g.size());i++){
        std::cin >> g[i].first >> g[i].second;
        p[i] = g[i].first;
    }
    int res = 0x3f3f3f3f;
    for(int i = 1;i <= n;i++) res = std::min(res,dfs(i,isDeath,1));
    // res = std::min(res,dfs(5,isDeath,1));
    std::cout << res << std::endl;
    return 0;
}