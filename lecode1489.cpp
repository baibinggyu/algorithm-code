#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;
class Solution {
public:
    int find(int x,vector<int> & pre){
        if(pre[x] != x) return pre[x] = find(pre[x],pre);
        return x;
    }
    // n 为点的个数,count 已经选中的个数
    int kruskal(vector<vector<int>>& edges,vector<bool>& vis,vector<int>& pre,int n,int count){
        int res = 0;
        // n - 1为边数
        for(int i = 0;i < edges.size() && count < n - 1;i++){
            if(vis[i]) continue;
            int a = find(edges[i][0],pre);
            int b = find(edges[i][1],pre);
            int w = edges[i][2];
            if(a != b){
                pre[a] = b;
                res += w;
                count++;
            }
        }
        if(count != n - 1) return INT_MAX;
        return res;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i = 0;i < edges.size();i++) edges[i].push_back(i); // 保留原始下标
        vector<bool> vis(edges.size(),false);
        vector<int> pre(n);
        iota(pre.begin(),pre.end(),0);
        sort(edges.begin(),edges.end(),[](vector<int>& a,vector<int>& b)->bool{return a[2] < b[2];});
        int minCount = kruskal(edges,vis,pre,n,0);

        vector<int> keyEdge;
        for(int i = 0;i < edges.size();i++){
            iota(pre.begin(),pre.end(),0);
            vis[i] = true;
            int cost = kruskal(edges,vis,pre,n,0);
            if(cost > minCount)
                keyEdge.push_back(edges[i][3]);
            vis[i] = false;
        }

        vector<int> noKeyEdge;
        for(int i = 0;i < edges.size();i++){
            if(std::find(keyEdge.begin(),keyEdge.end(),edges[i][3]) != keyEdge.end()) continue;
            iota(pre.begin(),pre.end(),0);
            pre[edges[i][0]] = edges[i][1];
            vis[i] = true;
            int cost = kruskal(edges,vis,pre,n,1) + edges[i][2];
            if(cost == minCount) noKeyEdge.push_back(edges[i][3]);
            vis[i] = false;
        }
        
        return {keyEdge,noKeyEdge};
    }
};  