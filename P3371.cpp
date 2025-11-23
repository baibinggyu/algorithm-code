#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <climits>
std::vector<int> dijkstra(std::vector<std::vector<std::pair<int,int>>>& edges,int start){
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> pq;
    std::vector<int> dist(edges.size(),INT_MAX);
    std::vector<int> vis(edges.size(),0);
    dist[start] = 0;
    pq.push({0,start});
    while(!pq.empty()){
        std::pair<int,int> p = pq.top();pq.pop();
        if(vis[p.second]) continue;
        vis[p.second] = true;
        for(auto& x : edges[p.second]){
            int w = x.first,v = x.second;
            if(dist[v] > dist[p.second] + w){
                dist[v] = dist[p.second] + w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}

int main(void){
    int n , m ,s;
    std::cin >> n >> m >> s;
    std::vector<std::vector<std::pair<int,int>>> edges(n + 1);
    for(int i = 0;i < m;i++){
        int u , v , w;
        std::cin >> u >> v >> w;
        edges[u].push_back({w,v});
    }
    std::vector<int> dist = dijkstra(edges,s);
    for (int i = 1;i < n + 1;i++) std::cout << dist[i] << ' ' ;
    std::cout << std::endl;
    return 0;
}