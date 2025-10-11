#include <bits/stdc++.h>
#define int long long 
#define SIZE 100
signed main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::vector<bool> isPrime(SIZE + 1,true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2;i * i < isPrime.size();i++){
        if(!isPrime[i]) continue;
        for(int j = i * i;j < isPrime.size();j += i){
            isPrime[j] = false;
        }
    }
    for(int i = 0;i < isPrime.size();i++)
        if(isPrime[i])
            std::cout << i << ' ' ;
    std::cout << std::endl;
    return 0;
}