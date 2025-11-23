#include <iostream>
#include <stack>
#define int long long
constexpr int N = 3e6;
int arr[N],ans[N];
std::stack<int> stk;

signed main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    for(int i = 1;i <= n;i++)
        std::cin >> arr[i];
   for(int i = n;i > 0;i--){    
        while(!stk.empty() && arr[i] >= arr[stk.top()]){
            stk.pop();
        }
        ans[i] = !stk.empty() ? stk.top() : 0;
        stk.push(i);
   }
    for(int i = 1;i <= n;i++)
        std::cout << ans[i] << ' ';
    return 0;
}