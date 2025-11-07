#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <utility>
#define int long long
constexpr int N = 1e6 + 5;
int n;
int w[N];
int real[N] , eW[N]; // 实际功率，额定功率
std::vector<int> leaf;
void dfs(int cur ,int val,std::vector<int>& parent){
    if(cur < 0) return ;
    real[cur] += val;
    dfs(parent[cur],val,parent);
}

signed main(void){
    std::cin >> n;
    std::vector<int> parent(n + 1);
    parent[0] = -1;
    std::unordered_map<int,bool> isParent;  
    eW[0] = 2200;
    for(int i = 1;i  < static_cast<int>(parent.size());i++){
        int p , weight;std::cin >> p >> weight;
        parent[i] = p;
        w[i] = weight;
        eW[i] = weight;
        isParent[p] = true;
    }
   for(int i = 1;i < n + 1;i++)
        if(not isParent.count(i)) leaf.emplace_back(i);
    for(auto& x : leaf) dfs(x,w[x],parent);
    if(real[0] > eW[0]) return std::cout << "NO" << std::endl,0;
    std::sort(std::begin(real) + 1,std::begin(real) + n + 1,std::greater<int>());
    std::sort(std::begin(eW) + 1,std::begin(eW) + n + 1,std::greater<int>());
    for(int i = 1 ;i < n + 1;i++)
        if(eW[i] < real[i]) return std::cout << "NO" << std::endl,0;
    std::cout << "YES" << std::endl;
    return 0; 
}   