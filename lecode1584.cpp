#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    struct Edge{
        int a,b;
        int w;
    };
    int find(int x,vector<int>& p){
        if(p[x] != x) return p[x] = find(p[x],p);
        return x;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int res = 0;
        vector<Edge> edge;
        vector<int> p;
        int n = points.size();
        for(int i = 0;i < n - 1;i++)        
            for(int j = i + 1;j < n;j++){
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edge.push_back({i,j,w});
            }
        sort(edge.begin(),edge.end(),[](Edge& a,Edge& b)->bool{return a.w < b.w;});
        for(int i = 0;i < n;i++) p.push_back(i);
        for(int i = 0;i < edge.size();i++){
            int a = find(edge[i].a,p);
            int b = find(edge[i].b,p);
            int w = edge[i].w;
            if(a != b){
                res += w;   
                p[a] = b;
            }
        }
        return res;
    }
};