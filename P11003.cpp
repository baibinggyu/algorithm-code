#include <iostream>
#define int long long
auto main(void) -> signed {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    if (n % 3 == 0)
      std::cout << 2 * n << std::endl;
    else
      std::cout << n << std::endl;
  }
}
