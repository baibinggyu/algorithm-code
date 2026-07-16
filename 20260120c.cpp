#include <algorithm>
#include <iostream>
#include <vector>
#define int long long
signed main(void) {
    int t;std::cin >> t;
    while (t--) {
       int k , x;std::cin >> k >> x;
        int target = 1ll << k;
        if (x == target) {
            std::cout << 0 << std::endl;
            continue;
        }
        int a =  x,b = (1ll << (k + 1)) - x;
        std::vector<int> res;
        while (a != b) {
            if (a > b) {
                res.push_back(2);
                int temp = a;
                a = a - b;
                b = b * 2;
            }else {
                res.push_back(1);
                b = b - a;
                a = a * 2;
            }
        }
        std::cout << res.size() << std::endl;
        for (auto p = res.rbegin();p != res.rend();p++)
            std::cout << *p << ' ';
        std::cout << std::endl;
    }
}