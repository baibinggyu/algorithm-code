#include <array>
#include <iostream>
#include <ranges>
#include <stack>
#include <vector>
#define int long long
enum class State { self = 0, next01 = 1, next02 = 2, next03 = 3 };
constexpr int MOD = 998244353;
auto main(void) -> signed {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> graph(n + 1);
  for (auto i : std::views::iota(1, n)) {
    int a, b;
    std::cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  std::vector<std::array<int, 4>> dp(n + 1);
  std::vector<int> parent(n + 1, 0);
  std::stack<int> stk;
  stk.push(1);
  std::vector<int> order; // record order of stack
  order.reserve(n);
  while (not stk.empty()) {
    auto cur = stk.top();
    stk.pop();
    order.push_back(cur);
    for (const auto x : graph[cur]) {
      if (x == parent[cur])
        continue;
      parent[x] = cur;
      stk.push(x);
    }
  }
  //  忽视空集，最后处理
  for (int i = n - 1; i >= 0; i--) {
    auto cur = order[i];
    int all_child_not_self = 1; // child not select themselves
    int all_child_not_near = 1; // child grandson not select
    int one_child_self = 0;     // only one child be selected
    for (auto const next : graph[cur]) {
      if (next == parent[cur])
        continue;
      int child_not_self = ((dp[next][static_cast<int>(State::next01)] % MOD) +
                            (dp[next][static_cast<int>(State::next02)] % MOD) +
                            (dp[next][static_cast<int>(State::next03)] % MOD)) %
                           MOD;
      int child_not_near = ((dp[next][static_cast<int>(State::next02)]) +
                            dp[next][static_cast<int>(State::next03)] % MOD) %
                           MOD;
      one_child_self =
          (((one_child_self * child_not_self) % MOD) +
           (dp[next][static_cast<int>(State::self)] * all_child_not_self) %
               MOD) %
          MOD;
      all_child_not_self = (all_child_not_self * child_not_self) % MOD;
      all_child_not_near = (all_child_not_near * child_not_near) % MOD;
    }
    dp[cur][static_cast<int>(State::self)] = all_child_not_near;
    dp[cur][static_cast<int>(State::next01)] = one_child_self;
    dp[cur][static_cast<int>(State::next02)] =
        (all_child_not_self - all_child_not_near + MOD) % MOD;
    dp[cur][static_cast<int>(State::next03)] = all_child_not_near;
  }

  int res{0};
  for (const auto x : dp[1])
    res = ((res % MOD) + (x % MOD)) % MOD;
  std::cout << ((res - 1 + MOD) % MOD) << std::endl;
}
