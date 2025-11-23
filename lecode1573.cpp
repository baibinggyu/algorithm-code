#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using std::string;
constexpr int N = 1e6 + 5;
constexpr int MOD =  1e9 + 7 ;
class Solution {
public:
    int numWays(string s) {
        int n = s.length();
        if(n < 3) return 0;
        int cnt = std::count(std::begin(s),std::end(s),'1');
        if(cnt == 0) {
            return ((n - 1) * 1ll* (n - 2) / 2) % MOD;
        } 
        std::cout << "到这里了" << std::endl;
        if(cnt % 3 != 0) return 0;
        int gap = cnt / 3 ;
        std::vector<int> arr;
        int count = 0;
        int sep = 0;
        for(int i = std::find(std::begin(s),std::end(s),'1') - s.begin() + 1;i < n;i++){
            if(s[i] == '1') {
                sep ++;
                if(sep == gap){
                    arr.emplace_back(count + 1);
                    sep = 0;
                }
                count = 0;
                continue;
            }
            count++;
        }
        int res = 1;
        for(auto& x : arr) res = ((res % MOD ) *1ll* (x % MOD)) % MOD;
        return res;
    }
};