#include <iostream>
#include <vector>
#include <utility>
constexpr int MAXB = 31;
std::vector<int> res(MAXB + 1,0);
struct Trie{
    int next[2];
    Trie(){next[0] = next[1] = -1;}
};
std::vector<std::vector<std::pair<int,int>>> tree;
std::vector<Trie> trie;
void dfs(std::vector<int>& xorVal,int u ,int fa, int val){
    xorVal[u] = val;
    for(auto [x , w] : tree[u]){
        if(x == fa) continue;
        dfs(xorVal,x,u,w xor val);
    }
}
void insert(int val){
    int p = 0;
    for(int i = MAXB;i >= 0 ;i--){
        int bit = (val >> i) & 1;
        if(trie[p].next[bit] == -1){
            trie[p].next[bit] = trie.size();
            trie.push_back({});
        } 
        p = trie[p].next[bit];
    }
}
int query(int x){
    int p = 0,res = 0;
    for(int i = MAXB;i >= 0;i--){
        int bit = (x >> i) & 1;
        int want = bit xor 1;
        if(trie[p].next[want] != -1){
            res |= (1 << i);
            p = trie[p].next[want];
        }else if(trie[p].next[bit] != -1){
            p = trie[p].next[bit];
        }
    }
    return res;
}
int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;std::cin >> n;
    tree = std::vector<std::vector<std::pair<int,int>>>(n + 1,std::vector<std::pair<int,int>>());
    for(int i =  1;i < n;i++){
        int u  , v , w;
        std::cin >> u >> v >> w;
        tree[u].push_back(std::make_pair(int(v),int(w)));
        tree[v].push_back(std::make_pair(int(u),int(w)));
    }
    trie.push_back({});
    std::vector<int> xorVal(n + 1,0);
    dfs(xorVal,1,0,0);
    int ans = 0;
    for(auto& x : xorVal){
        ans = std::max(ans,query(x));
        insert(x);
    }
    std::cout << ans << std::endl;
    return 0;
} 