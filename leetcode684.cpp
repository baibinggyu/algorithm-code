#include <iostream>
#include <vector>
using namespace std;
// 非暴力
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for(int i = 0;i < n + 1;i ++) father.emplace_back(i);
        for (int i = 1;i < this->father.size();i++){
            if(union_(edges[i][0],edges[i][1])){
                return edges[i];
            }
        }
        return {};
    }
    int find(int x){
        if(father[x] == x){
            return x;
        }
        return father[x] = find(father[x]);
    }
    bool union_(int a,int b){
        a = find(a);
        b = find(b);
        if(a == b){
            return false;
        }else if (a < b){
            father[b] = a;
        }else{
            father[a] = b;
        }
        return true;
    }
private:
    vector<int> father;
};
