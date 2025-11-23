#include <iostream>
#include <vector>
#define int long long 
int quick_pow(int a,int p,int mod){
    int res = 1;
    while(p){
        if (p & 1) res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }                               
    return res;
}
constexpr int SIZE = 3e6+5;
int hash[SIZE];
signed main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,p;
    std::cin >> n >> p;
    std::vector<int> ans;
    ans.push_back(1);
    for(int i = 2;i < n + 1;i++){
        int index = i % p;
        if (hash[index]) ans.push_back(hash[index]);
        else{
            hash[index] = quick_pow(index,p - 2,p) % p;
            ans.emplace_back(hash[index]);
        }
    }
    for(auto x : ans) std::cout << x << std::endl;
    return 0;
}