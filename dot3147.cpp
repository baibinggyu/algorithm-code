#include <iostream>
#include <vector>
int main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0;i < n;i++) std::cin >> arr[i];
   std::vector<int> cur(n + 1,0);
   for (int i = 1;i < cur.size();i++) cur[i] = cur[i - 1] ^ arr[i - 1];
   #define SIZE 21
    std::vector<int> p2(SIZE,1);
    std::vector<std::vector<int>> count(SIZE,std::vector<int>(2,0));
    for(int i = 1;i < SIZE;i++) p2[i] = p2[i - 1] * 2;
    for(int i = 0; i < SIZE ;i++){
        for(int j = 0;j <= n;j++){
           if((cur[j] >> i) & 1)
                count[i][1]++;
            else
                count[i][0]++;
        }
    }
    long long res = 0;
    for (int i = 0;i < SIZE;i++){
        //0 ≤ Ai ≤ 2^20 
        res +=1LL * count[i][1] * count[i][0] * p2[i];
    }
    std::cout << res << std::endl;
    return 0;
}