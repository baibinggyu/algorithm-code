#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define MOD 7
int ans;
std::stack<int> stk;
void dfs(std::vector<int>& id,int& sum,int index){
    if (index >= id.size()) return;
    stk.push(index);
    bool flag = ((sum + id[index] ) % MOD) == 0 ? true : false;
    if(flag) ans = std::max(ans,static_cast<int>(stk.size()));
    sum += id[index];
    dfs(id,sum,index + 1);
    sum -= id[index];
    stk.pop();
}

int main(void){
    int n;
    std::cin >> n;
    std::vector<int> id(n,-1);
    for (int i = 0;i < id.size();i++){
        std::cin >> id[i];
    }
    int sum = 0;
    for (int i = 0;i < id.size();i++){
        dfs(id,sum,i);
    }
    std::cout << ans << std::endl;
    return 0;
}