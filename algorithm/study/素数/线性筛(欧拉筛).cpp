#include <bits/stdc++.h>
#define int long long
#define SIZE 100
signed main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // 唯一分解定理
    // 任何大于1的正整数n都可以唯一分解为有限个质数的乘积
    std::vector<bool> isPrime(SIZE + 1,true);
    std::vector<int> primes;
    for(int i  = 2;i < isPrime.size();i++){
        if(isPrime[i]) primes.emplace_back(i);
        for(int j = 0;j < primes.size() && i * primes[j] < isPrime.size();j++){
            isPrime[i * primes[j]] = false;
            if(i % primes[j] == 0) break;
        }
    }
    for(int temp : primes)
        std::cout << temp << ' ' ;
    std::cout << std::endl;

    return 0;
}