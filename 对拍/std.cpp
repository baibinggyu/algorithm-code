#include <iostream>
int main(void){
    int a , b;
    std::cin >> a >> b;
    int sum = 0;
    for(int i = 0;i < a;i++) sum ++;
    for(int i = 0;i < b;i++) sum++;
    std::cout << sum << std::endl;
    return 0;
}