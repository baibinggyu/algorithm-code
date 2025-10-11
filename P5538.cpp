#include <iostream>
#include <vector>
#define MOD 786433

int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> arr(n + 1);
    for(int i = 0;i < arr.size();i++) std::cin >> arr[i];
    std::vector<std::vector<bool>> graph(n + 1,std::vector<bool>(n + 1,false));
    for(int i = 0;i < n - 1;i++){
        int u , v;
        std::cin >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }



    return  0;
}