#include <iostream>
#define int long long
constexpr int mod01 = 20250412, mod02 = 20240413;
auto solve(void) -> void {
  std::cout << -mod01 + mod02 * (mod01 - 1) << std::endl;
}
auto main(void) -> signed { solve(); }
