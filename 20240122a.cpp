#include <iostream>
#define int long long
signed  main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;std::cin >> t;
    while(t--){
        int n , a,  b;std::cin >> n >> a >> b;
        int ar = n - a + 1,br = n - b + 1;
        int mid = n >> 1;
        if(a <= b){
            if(b & 1){
                // b is odd
                if((n & 1) == 0) std::cout << "NO" << std::endl;
                else std::cout << "YES" << std::endl;
            }else{
                // b is even
                if((n & 1) == 0) std::cout << "YES" << std::endl;
                else std::cout << "NO" << std::endl;
            }
        }else{
            if(b & 1){
                // b is odd
                if((n & 1) == 0) {std::cout << "NO" << std::endl;continue;}
                
            }else{
                // b is even
                if((n & 1) == 1) {std::cout << "NO" << std::endl;continue;}
            }
            if(a & 1) {
                if((n & 1) == 0) std::cout << "NO" << std::endl;
                else std::cout << "YES" << std::endl;
            }else{
                if((n & 1) == 0) std::cout << "YES" << std::endl; 
                else std::cout << "NO" << std::endl;
            }
        }
    }
}
