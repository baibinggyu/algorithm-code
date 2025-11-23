#include <iostream>
#include <vector>
#include <climits>
constexpr int MAXN = 2e5 + 5;
int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,k,q;
    std::cin >> n >> k >> q;
    std::vector<int> diff(MAXN,0),count(MAXN,0),pre(MAXN,0);    
    int tempMin = INT_MAX;
    for (int i = 0 ;i < n;i++)
    {
        int l , r;
        std::cin >> l >> r;
        tempMin = std::min(tempMin,l);
        diff[l] += 1;
        diff[r + 1] -= 1;
    }
    int num = 0;
    for (int i = tempMin;i <= MAXN;i++){
        count[i] = count[i - 1] + diff[i];
        pre[i] = pre[i - 1] + (count[i] >= k ? 1 : 0);
    }
    while(q--){
        int l , r;
        std::cin >> l >> r;
        std::cout << pre[r] - pre[l - 1] << std::endl;
    }

    

    return 0;
}