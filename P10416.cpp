#include <iostream>
#define int long long
auto main(void) -> signed {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int left, right;
    std::cin >> left >> right;
    if (left == 0 and right == 0) {
      std::cout << 1 << std::endl;
      continue;
    }
    int p = right - left;
    if (p < left) {
      std::cout << 0 << std::endl;
      continue;
    }
    int n = p - left + 1;
    std::cout << (n * (n + 1) >> 1) << std::endl;
  }
}
