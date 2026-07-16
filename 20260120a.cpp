#include <iostream>
int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;std::cin >> n;
    for (int i = 0;i < n;i++) {
        int a, b;std::cin >> a >> b;
        if (a == b) std::cout << 0 << std::endl;
        else if (a % b == 0 or b % a == 0) std::cout << 1 << std::endl;
        else std::cout << 2 << std::endl;
    }
}
