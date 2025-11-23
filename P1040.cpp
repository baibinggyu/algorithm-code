#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <stack>
// void pre(std::vector<std::vector<int>>& root,std::vector<int>& ans,int l,int r){
//     if(l > r) return;
//     int cur = root[l][r];
//     ans.push_back(cur);
//     pre(root,ans,l,cur - 1);
//     pre(root,ans,cur + 1,r);
// }
void pre(std::vector<std::vector<int>>& root,std::vector<int>& ans){
    std::stack<std::pair<int,int>> stk;
    stk.push({1,root.size() - 1});
    while(!stk.empty()){
        auto [l , r]  = stk.top();
        stk.pop();
        if( l > r) continue;
        int cur = root[l][r];
        ans.push_back(cur);
        stk.push({cur + 1,r});
        stk.push({l , cur - 1});
    }
}
int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;std::cin >> n;
    std::vector<int> arr(n + 1,0);
    std::for_each(arr.begin() + 1,arr.end(),[](auto& x){std::cin >> x;});
    std::vector<int> res(n + 1,0);
    std::vector<std::vector<int>> dp(n + 1,std::vector<int>(n + 1,0));
    std::vector<std::vector<int>> root(n + 1,std::vector<int>(n + 1,0));
    for(int i = 1;i < n + 1;i++) dp[i][i] = arr[i],root[i][i] = i;
    for(int len = 2;len <= n;len++){
        for(int start = 1;start + len - 1 < n + 1;start++){
            int end = start + len - 1;
            for(int i = start;i < end;i++){
                int left = i > start ? dp[start][i - 1] : 1;
                int right = i < end ? dp[i + 1][end] : 1;
                int addSocre = left * right + arr[i];
                if(addSocre > dp[start][end]){
                    dp[start][end] = addSocre;
                    root[start][end] = i;
                }
            }
        }
    }
    std::cout << dp[1][n] << std::endl;
    std::vector<int> ans;
    // pre(root,ans,1,n);
    pre(root,ans);
    std::for_each(std::begin(ans),std::end(ans),[](auto& x){std::cout << x << ' ' ;});
    std::cout << std::endl;
    return 0;
}