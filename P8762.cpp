#include <functional>
#include <iostream>
#define int long long
constexpr int SIZE = 2e6 + 5;
inline int function(int n) { return (n * (n + 1)) >> 1; }
int lower(int target) {
  // find for max function return
  int l = 0, r = SIZE;
  int res = 0;
  while (l <= r) {
    int mid = ((r - l) >> 1) + l;
    int ans = function(mid);
    if (ans == target)
      return mid;
    else if (ans < target)
      l = mid + 1, res = mid;
    else
      r = mid - 1;
  }
  return res;
}
auto main(void) -> signed {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int l, r;
    std::cin >> l >> r;
    auto calac = std::function<int(int)>(
        [](int n) { return n * (n + 1) * (n + 2) / 6; });
    int left = lower(l - 1);
    int right = lower(r);
    int diffLeft = l - function(left);
    int diffRight = r - function(right);
    int sum = diffLeft + calac(right) - calac(left) + function(diffRight) -
              function(diffLeft);
    std::cout << sum << std::endl;
  }
}
