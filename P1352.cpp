#include <iostream>
#include <vector>
#include <algorithm>
constexpr int N = 6005;
int f[N][2]; // 0不参加 ，1参加
int dp[N][2];
void dfs(int usr,std::vector<std::vector<int>>& graph,std::vector<int>& happy){
    dp[usr][1] = happy[usr];
    dp[usr][0] = 0;
    for(int x : graph[usr]){
        dfs(x,graph,happy);
        dp[usr][0] += std::max(dp[x][1],dp[x][0]);
        dp[usr][1] += dp[x][0];
    }
}

int main(void){
    int n ;
    std::cin >> n;
    std::vector<int> happy(n + 1,0);
    for(int i = 1;i < happy.size();i++) std::cin >> happy[i];
    std::vector<std::vector<int>> graph(n + 1);
    std::vector<int> parent(n + 1);
    for(int i = 0 ;i < n - 1;i++){
        int a , b;
        std::cin >> a >> b;
        graph[b].emplace_back(a);
        parent[a] = b;
    }
    int root = 0;
    for(int i = 1;i < parent.size();i++) 
        if (parent[i] == 0){
            root = i;
            break;
        }
    dfs(root,std::ref(graph),std::ref(happy));
    std::cout << std::max(dp[root][1],dp[root][0]) << std::endl;
    return 0;
}