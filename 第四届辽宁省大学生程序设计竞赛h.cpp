#include <iostream>
int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--){
        int a , b , n;
        std::cin >> a >> b >> n;
        if(n & 1){
            std::cout << "Alice" << std::endl;
        }else{
            std::cout << "Bob" << std::endl;
        }
    }
    return 0;
}


// a^2 * x ^ 2 + ax + 1 mod 2 == ax + 1
// 1 


/*
    a * a * x * x + a * x + 1 >= 1
    if(CNT(a,1) < n) 先手必败
    n == 1 : 先手必胜
    n == 2 : 先手必败
    n == 3 : 先手必胜
    n == 4 : 先手必败
    n == 5 : 先手必胜

*/