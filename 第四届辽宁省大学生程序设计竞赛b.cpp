#include <iostream>
#include <cmath>
#include <algorithm>
#define SIZE 10000
int main(void){
    double x;std::cin >> x;
    int target = std::round(x * 100);
    for(int i = 1;i < SIZE;i++){
        int l = 0,r  = i;
        while(l <= r){
            int mid =l + ((r - l) >> 1);
            int div = std::round((mid * 1.0 / i) * 10000) ;
            if(div == target) {std::cout << i << std::endl;return 0;}
            else if(div < target){
                l = mid + 1;
            }else if(div > target){
                r = mid - 1;
            }
        }
    }
    return 0;
}