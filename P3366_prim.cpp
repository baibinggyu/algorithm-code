#include <iostream>
#include <queue>
#include <vector>
#include <utility>
int prim(int start,std::vector<std::vector<std::pair<int,int>>>& graph){
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> pq;
    pq.push({0,start});
    int res = 0;
    std::vector<bool> vis(graph.size(),false);
    while(!pq.empty()){
        auto [w , u] = pq.top();pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        res += w;
        for(auto& x : graph[u]){
            pq.push({x.second,x.first});
        }
    }
    for(int i = 1;i < vis.size();i++)
        if(!vis[i]) return -1;
    return res;
}
int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n , m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int,int>>> graph(n + 1);
    for(int i = 0;i < m;i++){
        int x , y , z;
        std::cin >> x >> y >> z;
        graph[x].push_back({y,z});
        graph[y].push_back({x,z});
    }
    int flag = prim(1,graph);
    if(flag == -1) std::cout << "orz" << std::endl;
    else std::cout << flag << std::endl;
    return 0;
}