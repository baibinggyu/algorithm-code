#include <iostream>
int main(void){
    srand(time(nullptr));
    int a = rand() % 100,b = rand() % 100;
    std::cout << a << ' ' << b;
    return 0;
}