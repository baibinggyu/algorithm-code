#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
signed main(void) {
    int n;std::cin >> n;
    for (int i = 0; i < n; i++) {
        int a , b;std::cin >> a >> b;
        std::vector<int> arr(a);
        for (auto& x : arr) std::cin >> x;
        std::sort(arr.begin(), arr.end(),std::greater<int>());
        int sum = 0;
        for (int j = 0;j < a;j++) {
            int t = b - j;
            if (t <= 0 ) break;
            sum += arr[j] * t;
        }
        std::cout << sum << std::endl;
    }
}