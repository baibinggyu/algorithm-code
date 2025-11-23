#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
// 双向搜索
void Print(std::vector<long long>& arr){
    std::for_each(arr.begin(),arr.end(),[](auto& x){std::cout << x << ' ';});
    std::cout << std::endl;
}
int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    long long  m;
    std::cin >> n >> m;
    std::vector<long long> left(n >> 1),right(n - (n >> 1));
    std::for_each(std::begin(left),std::end(left),[](auto& x){std::cin >> x;});
    std::for_each(std::begin(right),std::end(right),[](auto& x){std::cin >> x;});
    std::vector<long long> leftSub,rightSub;

    for(int i = 0;i < (1 << static_cast<int>(left.size()));i++){
        long long sum = 0;
        for(int j = 0;j < static_cast<int>(left.size());j++){
            if(i & (1 << j)) sum += left[j];
        }
        leftSub.emplace_back(sum);
    }
    for(int i = 0;i < (1 << static_cast<int>(right.size()));i++){
        long long sum = 0;
        for(int j = 0;j < static_cast<int>(right.size());j++){
            if(i & (1 << j)) sum += right[j];
        }
        rightSub.emplace_back(sum);
    }
    
    long long ans = 0;
    std::sort(rightSub.begin(),rightSub.end(),std::less<long long>());
    for(int i = 0;i < static_cast<int>(leftSub.size());i++){
        if(leftSub[i] > m) continue;
        ans += std::upper_bound(std::begin(rightSub),std::end(rightSub),m - leftSub[i]) - rightSub.begin();
    }
    std::cout << ans  << std::endl;
    return 0;
}