#include <iostream>
#include <vector>
int main(void){
   int n;std::cin >> n;
   if(n == 0) return std::cout << "fmt error" << std::endl,0;
   std::vector<bool> isPrime(n + 1,true);
     std::vector<int> p;
   isPrime[0] = isPrime[1] = false;
   for(int i = 2;i < isPrime.size();i++){
        if(isPrime[i]) p.push_back(i);
        for(auto& x : p){
            if(isPrime.size() >= i * x){
                if(isPrime[i * x]){
                    isPrime[i * x] = false;
                }
            }else break;
            if(i % x == 0) break;                    
        } 

   }
   for(auto& x : p) std::cout << x << ',';
   std::cout <<  std::endl;
}
