#include <iostream>
#include <unordered_map>
#define int long long
constexpr int mod = 9901;
int quick_pow(int a, int p) {
  int res = 1;
  if (a == 1 || p == 0)
    return 1;
  while (p) {
    if ((p & 1) == 1)
      res = (res % mod) * (a % mod) % mod;
    p = p >> 1;
    a = (a % mod) * (a % mod) % mod;
  }
  return res;
}
int exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = exgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return d;
}
int calc_sum(int p, int n) {
  if (p % mod == 1)
    return n % mod;
  int inv;
  int y;
  exgcd(p - 1, mod, inv, y);
  return ((quick_pow(p, n) - 1) % mod) * ((inv + mod) % mod) % mod;
}
auto main(void) -> signed {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int a, b;
  std::cin >> a >> b;
  // break down prime
  std::unordered_map<int, int> cnt;
  for (int i = 2; i <= a; i++) {
    if (a % i == 0) {
      cnt[i]++;
      a /= i;
      i--;
      continue;
    }
  }
  int res = 1;
  for (const auto &x : cnt) {
    res = ((res % mod) * (calc_sum(x.first, b * x.second + 1))) % mod;
  }
  std::cout << (res + mod) % mod << std::endl;
}
