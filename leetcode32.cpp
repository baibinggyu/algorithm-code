//没有完全掌握
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int longestValidParentheses(string s) {
            int n = s.size();
            if(n == 0 || n == 1) return 0;
            vector<int> dp(n,0);
            for(int i = 1;i < n;i++)
            {
                if(s[i] == ')')
                {
                    if(s[i-1] == '(')
                    {
                        dp[i] = 2;
                        if(i >= 2 and s[i-2] == ')')
                        {
                            dp[i] = dp[i] + dp[i-2];
                        }
                    }
                    else if (s[i-1] == ')')
                    {
                        int t = dp[i-1];
                        if(i - t - 1 >= 0 and s[i - t - 1] == '(')
                        {
                            dp[i] = 2;
                            dp[i] = dp[i] + t;
                            if(i - t - 2 >= 0 and s[i - t- 2] == ')')
                            {
                                dp[i] = dp[i] + dp[i - t - 2];
                            }
                        }
                    }
                }
               
            }
            int res = INT_MIN;
            for(int i = 0 ;i < n;i++)
                res = max(dp[i],res);
            return res;
            
        }
    };