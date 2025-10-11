#include <iostream>
#include <cmath>
#include <algorithm>
int main(void){
    long long  a , b;
    std::cin >> a >> b;
    double phi = (std::sqrt(5.0) + 1) / 2;
    if (a > b) std::swap(a,b);
    long long  k = b - a;
    if (static_cast<long long>(phi * k) ==  a) std::cout << 0 << std::endl;
    else std::cout << 1 << std::endl;
    return 0;
}