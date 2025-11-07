#include <vector>
#include <algorithm>
#include <iostream>
constexpr int N = 1e6 + 5;
constexpr int SIZE = 20;
int depth[N];
int up[N][SIZE];

void dfs(int u , int parent,std::vector<std::vector<int>>& graph){
    up[u][0] = parent;
    for(int i = 1 ;i < SIZE;i++){
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for(auto& x : graph[u]){
        if(x == parent) continue;
        depth[x] = depth[u] + 1;
        dfs(x,u,graph);
    }
}

int lca(int u ,int v){
    if(depth[u] < depth[v]) std::swap(u,v);
    int diff = depth[u] - depth[v];
    for(int i = 0;i < SIZE;i++){
        if(diff >> i & 1){
            u = up[u][i];
        }
    }
    if(u == v) return u;
    for(int i = SIZE - 1;i >= 0;i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main(void){
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    int n , m ;
    ::scanf("%d%d",&n,&m);
    std::vector<std::vector<int>> graph(n + 1,std::vector<int>());
    for(int i = 1;i < n;i++){
        int  a, b;
        ::scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,1,graph);
    for(int i = 0;i < m;i++){
        int x , y ,z;
        ::scanf("%d%d%d",&x,&y,&z);
        int a =  lca(x,y) , b = lca(x,z) ,c = lca(y,z);
        int p = depth[a] > depth[b] ? a : b;
        p = depth[p] > depth[c] ? p : c;
        int disSum = 3 * depth[p] + depth[x] + depth[y] + depth[z] - 2 * ( depth[lca(p,x)]  + depth[lca(p,y)] + depth[lca(p,z)]);
        ::printf("%d %d\n",p,disSum);
    }

    return 0;           
}