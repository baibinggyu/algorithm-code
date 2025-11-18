#include <iostream>
#include <vector>
#include <algorithm>
constexpr int N = 1e6 + 5;
std::vector<int> prime;
std::vector<int> phi;
bool vis[N];
int n;

void eurle(){
    phi[0] = phi[1] = 1;
    for(int i = 2; i <= n;i++){
        if(not vis[i]){
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for(auto& x : prime){
            int next = x * i;
            if(next > n) break;
            vis[next] = true;
            if(i % x == 0){
                phi[next] = phi[i] * x;
            }else{
                phi[next] = phi[i] * (x - 1);
            }
        }
    }
}
int main(void){
    std::cin >> n;
    if(n == 1) return std::cout << 0 << std::endl,0;
    phi.assign(n + 1,0);
    eurle();
    int res = 3;
    for(int i = 2;i < n;i++) res += (phi[i] << 1);
    std::cout << res << std::endl;
    return 0;
}