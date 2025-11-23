#include <iostream>
#include <vector>
void Print(std::vector<int>& arr){
    for(int x : arr) std::cout << x << ' ' ;
    std::cout << std::endl;
}
int main(void){
    int target;
    std::cin >> target;
    int n = target >> 1;
    std::vector<bool> isPrime(n + 1,true);
    std::vector<int> prime;
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2;i < static_cast<int>(isPrime.size());i++){
        if(isPrime[i]) {
            prime.push_back(i);
            if(target  % prime.back() == 0){
                std::cout << target / prime.back() << std::endl;
                break; 
            }
        }
        for(int x : prime){
            if (x * i < static_cast<int>(isPrime.size()))
                isPrime[x * i] = false;
            if(i % x == 0) break;
        }
    }

    return 0;
}