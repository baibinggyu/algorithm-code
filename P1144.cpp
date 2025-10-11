#include <iostream>
#include <vector>
#include <queue>
constexpr int MOD = 100003;
int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n , m ;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n + 1);
    for(int i = 0;i < m;i++){
        int x , y;
        std::cin >> x  >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    std::queue<int> q;
    std::vector<int> ans(n + 1,0);
    ans[1] = 1;
    std::vector<int> dist(n + 1,-1);
    dist[1] = 0;
    q.push(1);
    while(!q.empty()){
        int u = q.front();q.pop();
        for(auto& x : graph[u]){
            if(dist[x] == -1){
                dist[x] = dist[u] + 1;
                ans[x] = ans[u];
                q.push(x);
            }else if (dist[x] == dist[u] + 1){
                ans[x] = (ans[x] + ans[u]) % MOD;
            }
        }
    }
    for(int i = 1;i < (int)ans.size();i++) std::cout << ans[i] % MOD << std::endl;
    return 0;
}                