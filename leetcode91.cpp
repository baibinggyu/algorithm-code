#include <string>
#include <vector>
using std::string;
class Solution {
public:
    int numDecodings(string s) {
        std::vector<int> dp(s.length() + 1,0);
        if(s[0] == '0') return 0;
        dp[0] = 1,dp[1] = 1;
        for (int i =  2;i < dp.size();i++){
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];
            int num = std::atoi(s.substr(i - 2,2).c_str());
            if (num >= 10 && num <= 26){
                dp[i] += dp[i - 2];
            }
            if(num == 0 ) return 0;
        }
        return dp.back();
    }
};