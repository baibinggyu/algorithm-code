#include <iostream>
#include <vector>
#define int long long
constexpr int MOD = 1e9 + 7;
constexpr int SIZE = 200;
std::vector<std::vector<int>> f(SIZE, std::vector<int>(SIZE, -1));
std::vector<int> arr(SIZE);
// top is before current jugement {is top}
// top befron cur is whether 0
// true is ok before ,false if not ok before
auto dfs(int x, int sum, bool top) -> int {
  if (not x)
    return sum;
  if (not top and f[x][sum] >= 0)
    return f[x][sum];
  int curNumMax = top ? arr[x] : 9;
  int ret = 0;
  for (int i = 0; i <= curNumMax; i++)
    ret =
        (ret % MOD + dfs(x - 1, sum + i, top && (curNumMax == i) % MOD) + MOD) %
        MOD;
  if (not top)
    f[x][sum] = ret;
  return ret;
}
auto solve(int x) -> int {
  if (x == 0)
    return 0;
  int howBit{0};
  // from button to top
  while (x) {
    arr[++howBit] = x % 10;
    x /= 10;
  }
  return dfs(howBit, 0, true);
}
auto main(void) -> signed {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int left, right;
    std::cin >> left >> right;
    std::cout << (solve(right) - solve(left - 1) + MOD) % MOD << std::endl;
  }
}
