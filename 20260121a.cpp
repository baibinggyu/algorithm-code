#include <iostream>
#include <algorithm>
#define int long long
signed main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;std::cin >> t;
    while(t--){
    int a , b, c ,d;std::cin >> a >> b >> c >> d;
    c = c -a;
    d = d -b;
    if(a > b) std::swap(a,b);
    if(c > d) std::swap(c,d);
    if(a * 2 + 2 < b or c * 2 + 2 < d) std::cout << "NO" << std::endl;
    else std::cout << "YES" << std::endl;
    }
}
// 0 0
// 0 1
// 0 2
// 0 3
// 0 4 --> NO
// 1 1 
// 1 2 
// 1 3
// 1 4
// 1 5
// 1 6 --> NO
