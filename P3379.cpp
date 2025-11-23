#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
std::vector<std::vector<int>> graph;
constexpr int SIZE = 5e5 + 5;
constexpr int LOG = 20;
int up[SIZE][LOG];
int depth[SIZE];

void dfs(int u ,int v){
    up[u][0] = v;
    for(int i = 1;i < LOG;i++){
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for(auto& x : graph[u]){
        if(x == v) continue;
        depth[x] = depth[u] + 1;
        dfs(x,u);
    }
}
int lca(int u ,int v){
    if(depth[u] > depth[v]) std::swap(u,v);
    int diff = depth[v] - depth[u];
    for(int i = 0;i < LOG;i++){
        if(diff >> i & 1)
            v = up[v][i];
    }
    if(u == v) return u;
    for(int i = LOG - 1;i >= 0;i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main(void){
    int n , m , s;
    std::cin >> n >> m >> s;
    graph.resize(n + 1);
    for(int i = 0;i < n - 1;i++){
        int u ,  v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(s,s);
    for(int i = 0;i < m;i++){
        int node01 ,node02;
        std::cin >> node01 >> node02;
        std::cout << lca(node01,node02) << std::endl;
    }

    return 0;
}