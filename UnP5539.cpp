#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
int n , size;
std::map<int,bool> hash;
std::vector<int> arr;
#define int long long
int exgcd(int a, int b,int & x,int & y){
    if(b == 0 ){x = 1,y = 0;return a;}
    int x1,y1;
    int d = exgcd(b,a % b,x1,y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}
int gcd(int a , int b){
    if(b == 0) return a;
    return gcd(b , a % b);
}
// 合并两条同余方程 x ≡ r1 mod m1, x ≡ r2 mod m2
// x = k1m1 + r1,x = k2m2 + r2
// k1m1 - k2m2 = r2 - r1
bool merge(int r1,int m1,int r2,int m2,int &r,int &m){
    int x , y;
    int d = exgcd(m1,m2,x,y);
    if((r2 - r1) % d != 0) return false;
    m = m1 / d * m2;
    int64_t t = (r2 - r1) / d * x;
    t %= (m2 / d);
    r = (r1 + t * m1) % m;
    if(r < 0 ) r += m;
    return true;
}

signed main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> size;
    for(int i = 0;i < size;i++){
        int x; std::cin >> x;
        if(hash.count(x)) continue; else hash[x] = true;
        arr.emplace_back(x);
    }
    int ans = 0;
    for(int i = 0;i < static_cast<int>(arr.size());i++)
        for(int j = 0 ;j < static_cast<int>(arr.size());j++)
            for(int k = 0;k < static_cast<int>(arr.size());k++){
                int r , l;
                if(!merge(0,arr[i],1,arr[j],r,l)) continue;
                if(!merge(r,l,2,arr[k],r,l)) continue;
                if(r > n ) continue;
                
                ans += (n - r) / l + 1;
            }
    std::cout << ans << std::endl;
    return 0;
}