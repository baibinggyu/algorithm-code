# 一、Trie 树是什么

Trie 树，也叫 **字典树**，是一种 **多叉树**，专门用来存储 **字符串集合**。

**核心思想**：

- 每个节点代表一个字符串的前缀（从根到该节点的路径）。
- 根节点表示空字符串。
- 每个边对应一个字符。
- 一个节点可以标记为 **某个字符串的结尾**。

------

## 1️⃣ 举个例子

假设有字符串集合：`{"apple", "app", "bat", "bath"}`

Trie 树结构：

```
         (root)
        /     \
       a       b
       |       |
       p       a
       |       |
       p       t
       |       |
       l       h
       |       
       e       
```

说明：

- `app` 是字符串结尾 → 在 `p` 节点标记 isEnd = true
- `apple` 也是结尾 → 在 `e` 节点标记 isEnd = true
- 前缀查询很快，比如 `"ap"` → 只需走 `a->p` 即可

------

# 二、Trie 树节点结构

Trie 节点通常包含两类信息：

1. 指向子节点的指针（或数组）
2. 是否是字符串结尾

### 简单 C++ 写法（小写字母 a-z）

```cpp
struct TrieNode {
    TrieNode* child[26]; // 子节点指针
    bool isEnd;          // 是否是字符串结尾
    TrieNode() {
        memset(child, 0, sizeof(child));
        isEnd = false;
    }
};
```

------

# 三、基本操作

## 1️⃣ 插入字符串

```cpp
void insert(TrieNode* root, const string& s) {
    TrieNode* node = root;
    for (char c : s) {
        int idx = c - 'a';
        if (!node->child[idx]) node->child[idx] = new TrieNode();
        node = node->child[idx];
    }
    node->isEnd = true;
}
```

**分析：**

- 从根节点开始，沿着每个字符走。
- 如果节点不存在，就创建新节点。
- 最后一个字符节点标记为字符串结尾。

------

## 2️⃣ 查询字符串

```cpp
bool search(TrieNode* root, const string& s) {
    TrieNode* node = root;
    for (char c : s) {
        int idx = c - 'a';
        if (!node->child[idx]) return false; // 路径不存在
        node = node->child[idx];
    }
    return node->isEnd; // 只有结尾才算完整字符串
}
```

------

## 3️⃣ 查询前缀

```cpp
bool startsWith(TrieNode* root, const string& prefix) {
    TrieNode* node = root;
    for (char c : prefix) {
        int idx = c - 'a';
        if (!node->child[idx]) return false;
        node = node->child[idx];
    }
    return true; // 能走到最后，说明前缀存在
}
```

------

# 四、Trie 的优化

1. **使用数组代替指针 + 内存池**

   - 避免 `new` 频繁申请内存
   - 适合比赛场景

2. **统计前缀出现次数**

   ```cpp
   int cnt[MAXN]; // 每个节点经过次数
   insert时 node->cnt++
   ```

   - 可以快速求某个前缀出现次数

3. **删除字符串**

   - 复杂一些，需要判断节点是否还有其他子节点

4. **使用 map 或 unordered_map**

   - 适合字符集大（如 ASCII 全集、中文）

------

# 五、ACM 完整模板（数组 + 内存池 + 计数 + 删除）

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000; // 最大节点数
const int ALPHA = 26;     // 字符集 a-z

struct Trie {
    int ch[MAXN][ALPHA]; // 子节点
    int cnt[MAXN];       // 字符结尾计数
    int pre[MAXN];       // 前缀计数
    int sz;              // 节点总数

    Trie() { sz = 1; memset(ch[0], 0, sizeof(ch[0])); pre[0] = cnt[0] = 0; }

    void insert(const string &s) {
        int u = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (!ch[u][idx]) ch[u][idx] = sz++;
            u = ch[u][idx];
            pre[u]++; // 前缀计数
        }
        cnt[u]++;   // 完整字符串计数
    }

    bool search(const string &s) {
        int u = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (!ch[u][idx]) return false;
            u = ch[u][idx];
        }S
        return cnt[u] > 0;
    }

    bool startsWith(const string &prefix) {
        int u = 0;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!ch[u][idx]) return false;
            u = ch[u][idx];
        }
        return pre[u] > 0;
    }

    void erase(const string &s) { // 删除字符串
        if (!search(s)) return;
        int u = 0;
        for (char c : s) {
            int idx = c - 'a';
            u = ch[u][idx];
            pre[u]--;
        }
        cnt[u]--;
    }
};

int main() {
    Trie trie;
    int n;
    cin >> n;
    while (n--) {
        string op, s;
        cin >> op >> s;
        if (op == "insert") trie.insert(s);
        else if (op == "erase") trie.erase(s);
        else if (op == "search") cout << trie.search(s) << endl;
        else if (op == "prefix") cout << trie.startsWith(s) << endl;
    }
    return 0;
}
```

**特点：**

- `insert` 支持统计前缀次数
- `erase` 支持删除字符串
- `search` 精确查找
- `startsWith` 前缀查找