#include <iostream>
#define int long long
signed main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}
// gcd >= k
// a = qk + r
// a' = qk + r + add * k
// a' === r (mod k)
//
