#include <iostream>
#include <algorithm>
#include <vector>
#define int long long 
constexpr int N = 1e6 + 5;
int hash[N] = {0};
int fact(int a,int p){
    if(a < 0 ) return -1;
    if(a == 0 | a == 1) return 1;
    int res = 1;
    for(int i = 2;i <= a;i++) res = (res % p) * (i % p) % p;
    return res;
}
int pow_quick(int a,int p,int mod){
    if(p == 0) return 1;
    int res = 1;
    while(p ){
        if(p & 1) res = (res % mod) * (a % mod) % mod;
        a = (a % mod) * (a % mod) % mod; 
        p >>= 1;
    }
    return res;
}
int inverse(int a,int p ){
    // 欧拉
    return pow_quick(a,p - 2,p);
}
int C(int a , int b,int p){
    if(a < 0 or b <= 0 or a > b) return 0;
    if(a == 0) return 1;
    return ((fact(b,p) % p) * (inverse(fact(a,p),p) % p) * (inverse(fact(b - a,p),p) % p)) % p;
}
int lucas(int a,int b,int p){
    if(b == 0) return 1;
    if(b < a) return 0;
    return C(a % p,b % p,p) * lucas(a / p,b / p,p) % p;
}   
signed main(void){
    int t;
    std::cin >> t;
    while(t--){ 
        int n , m ,p;
        std::cin >> n >> m >> p;
        std::cout << lucas(n,n + m,p) % p << std::endl;
    }
    return 0;
}
    