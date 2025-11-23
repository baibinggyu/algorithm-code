#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

constexpr int mod = 1e9 + 7;;

signed main(void){
    int N;
    std::cin >> N;
    int Ma;
    std::cin >> Ma;
    std::vector<int> arr01(Ma);
    for(int i = arr01.size() - 1;~i;i--)
        std::cin >> arr01[i];
    int Mb;
    std::cin >> Mb;
    std::vector<int> arr02(Mb);
    for(int i = arr02.size() - 1;~i;i--)
        std::cin >> arr02[i];
    std::vector<int> hashBit(std::max(arr01.size(),arr02.size()) + 1);
    hashBit[0] = 1;
    int index = std::min(arr01.size(),arr02.size());
    for(int i = 0;i < index;i++){
        hashBit[i + 1] = std::max(arr01[i],arr02[i]) + 1;
        hashBit[i + 1] = std::max(hashBit[i + 1],2ll);
    }
    std::vector<int>& temp = arr01.size() > arr02.size() ? arr01 : arr02;
    for(int i = index;i < temp.size();i++){
        hashBit[i + 1] = std::max(temp[i] + 1,2ll);
    }   
    std::vector<int>& temp02 = arr01.size() > arr02.size() ? arr02 : arr01;
    int res = 0;
    int cur =  1;
    int isDeb = 0;
    for(int i = 0;i < temp02.size();i++){
        cur = cur * hashBit[i] % mod;
        res = (res + ((temp[i] - temp02[i])) * cur) % mod;
    }
    for(int i = temp02.size();i < temp.size();i++){
        cur = cur * hashBit[i] % mod;
        res = (res + temp[i] * cur) % mod;
    }
    res = res > 0 ? res : -res;
    std::cout << res % 1000000007 << std::endl;
    return 0;
}