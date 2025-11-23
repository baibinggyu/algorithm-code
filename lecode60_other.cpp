#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
    public:
        string getPermutation(int n, int k) {
            string res;
            vector<int> fact(n + 1);
            fact[0] = 1;
            for(int i = 1;i < n + 1;i++)
                fact[i] = i * fact[i-1];
            vector<bool> hash(n+1,false);
            for(int i = 0;i < n;i++){
                int cnt = fact[n - 1 -i];
                for(int i = 1;i <= n;i++){
                    if(hash[i]) continue;
                    if(cnt < k) k -= cnt;
                    else{
                        res += to_string(i);
                        hash[i] = true;
                        break;
                    }
                }

            }
            return res;
        }
    };