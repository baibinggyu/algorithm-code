#include <iostream>
#define int long long
void solve() {
  int n;
  std::cin >> n;
  int a = 45, b = 2;
  while (n > a) {
    b++;
    n -= a;
    a *= 5;
  }
  a /= 9;
  n--;
  bool flag = (n / a + 1) & 1;
  std::cout << (n / a + 1);
  for (int i = 1; i < b; i++) {
    n %= a;
    a /= 5;
    std::cout << (n / a * 2 + 1) - flag;
    flag = not flag;
  }
}
auto main(void) -> signed { solve(); }
