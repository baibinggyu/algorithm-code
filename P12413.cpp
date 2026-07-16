#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
#define int long long
auto calc(std::vector<int> &arr, int p) -> int {
  int res = 0;
  std::for_each(std::begin(arr), std::end(arr), [&res, &p](auto &x) {
    int diff = x - p > 0 ? x - p : 0;
    p++;
    res += diff;
  });
  return res;
}
auto main(void) -> signed {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int n, w;
  std::cin >> n >> w;
  std::vector<int> arr(n);
  std::for_each(std::begin(arr), std::end(arr), [](auto &x) { std::cin >> x; });
  std::sort(std::begin(arr), std::end(arr), std::less<int>());
  // std::for_each(std::begin(arr), std::end(arr),
  //               [](const auto &x) { std::cout << x << ' '; });
  int l = 0, r = 2e9;
  int cost = LONG_LONG_MAX;
  // for (int i = 0; i <= 4; i++) {
  //   std::cout << "cur = " << i << ':' << std::endl;
  //   std::cout << (calc(arr, i) + i * w) << std::endl;
  // }
  // int count = 0;
  while (l <= r) {
    // std::cout << "cur l = " << l << " cur r = " << r << std::endl;
    int mid = ((r - l) >> 1) + l;
    int midValue = calc(arr, mid) + mid * w,
        midPlusOneValue = calc(arr, mid + 1) + (mid + 1) * w;
    cost = std::min({midValue, midPlusOneValue, cost});
    // std::cout << "cost = " << cost << std::endl;
    if (midValue == midPlusOneValue)
      break;
    else if (midValue < midPlusOneValue)
      r = mid - 1;
    else
      l = mid + 1;
    // std::cout << leftValue << ' ' < midValue << ' ' << rightValue <<
    // std::endl;

    // if (++count == 20)
    //   break;
  }
  std::cout << cost << std::endl;
}
