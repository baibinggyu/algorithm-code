#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
#define int long long
constexpr int SIZE = 400 + 5;
std::vector<std::vector<int>> dp(SIZE, std::vector<int>(SIZE, LONG_LONG_MAX));
auto main(void) -> signed {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  int k;
  std::cin >> k;
  std::vector<int> arr(n + 1, 0);
  int sum = 0;
  std::for_each(std::begin(arr) + 1, std::end(arr), [&sum](auto &x) {
    std::cin >> x;
    sum += x;
  });
  dp[0][0] = 0;
  {
    int mx = INT_MIN;
    for (int j = 1; j <= n; j++) {
      mx = std::max(mx, arr[j]);
      dp[j][0] = mx * j;
    }
  }
  for (int j = 1; j <= k; j++) {
    for (int i = 1; i <= n; i++) {
      int mx = INT_MIN;
      for (int p = i; p >= 1; p--) {
        mx = std::max(mx, arr[p]);
        if (dp[p - 1][j - 1] != LONG_LONG_MAX)
          dp[i][j] = std::min(dp[i][j], dp[p - 1][j - 1] + mx * (i - p + 1));
      }
    }
  }

  std::cout << dp[n][k] - sum << std::endl;
}
