#include <iostream>
#define P 19260817
int exgcd(int a,int b,int& x,int& y){
    if(b == 0) return x = 1,y = 0,a;
    int x1 , y1;
    int g = exgcd(b,a % b,x1,y1);
    x = y1;
    y = x1 - a / b * y1;
    return g;
}

signed main(void){
    int a , b;
    std::cin >> a >> b;
    int x,y;
    int g = exgcd(b,P,x,y);
    if(g != 1){
        std::cout << "Angry!" << std::endl;
    }else{
        std::cout << (1ll * (x % P + P) % P) * (a % P) % P << std::endl;
    }

    return 0;
}