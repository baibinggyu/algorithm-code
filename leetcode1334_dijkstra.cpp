#include <vector>
#include <queue>
using std::vector;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        std::vector<std::vector<std::pair<int,int>>> graph(n);
        for(auto x : edges){
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
        int ret = n - 1;
        std::vector<int> arr(n);
        for(int i = n - 1;i >= 0;i--){
            arr[i] = dijkstra(i,graph,distanceThreshold);
            if(arr[ret] > arr[i]) ret = i;
        }
        return ret;
    }
    int dijkstra(int start,std::vector<std::vector<std::pair<int,int>>>& graph,int distance){
        int n = graph.size();
        std::vector<int> dist(n,0x3f3f3f3f);
        dist[start] = 0;
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> pq;
        pq.push({0,start});
        while(!pq.empty()){
            auto [v , u] = pq.top();pq.pop();
            if(v > dist[u]) continue;
            for(auto& x : graph[u]){
                if(dist[x.first] > dist[u] + x.second){
                    dist[x.first] = dist[u] + x.second;
                    pq.push({dist[x.first],x.first});
                }
            }
        }
        int res = 0;
        for(auto& x : dist)
            if (x <= distance)
                res++;
        return res;
    }
};