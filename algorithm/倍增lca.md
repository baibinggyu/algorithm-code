```c++
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;   // 最大节点数
const int LOG = 20;        // 2^20 = 1,048,576 > 1e5
// n —— 节点数（树的大小）
// q —— 查询次数（要问多少次 LCA）
int n, q;
vector<int> g[MAXN];
int up[MAXN][LOG];         // up[v][k] = v 的第 2^k 个祖先
int depth[MAXN];

// 建树：无向图
void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

// 预处理：DFS
// v：当前正在访问的节点（current vertex）
// p：v 的父节点（parent）
void dfs(int v, int p) {
    up[v][0] = p;
    for (int i = 1; i < LOG; i++)
        up[v][i] = up[ up[v][i-1] ][i-1];
  
    for (int to : g[v]) {
        if (to == p) continue;
        depth[to] = depth[v] + 1;
        dfs(to, v);
    }
}

// LCA 查询
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    // 1️⃣ 先抬高 u
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++)
        if (diff >> i & 1)
            u = up[u][i];

    // 2️⃣ 若相等，直接返回
    if (u == v) return u;

    // 3️⃣ 从高位向下跳
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }

    // 4️⃣ 返回父节点
    return up[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        add_edge(u, v);
    }

    // 任意设根（通常是 1）
    depth[1] = 0;
    dfs(1, 1);

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
}

```

