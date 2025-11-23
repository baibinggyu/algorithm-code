#include <iostream>
#include <algorithm>
#include <cmath>
#define int long long 
signed main(void){
    int x , y;
    std::cin >> x >> y;
    int product = x * y;
    int count = 0;
    for(int i = 1;i <=  sqrt(product);i++){
        int mod = std::__gcd(i,product / i);
        if(product % i == 0 &&  product / mod == y && mod == x) count++;
    }
    if (x == y) std::cout << count * 2 - 1 << std::endl;
    else std::cout << count * 2 << std::endl;
    return 0;
}


// PQ / X == Y
// PQ  == XY