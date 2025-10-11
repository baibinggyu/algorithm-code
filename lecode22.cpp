#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void dfs(vector<string> &res,string &ans,int sum,int left,int n)
        {
            if(sum == n * 2){
                res.push_back(ans);
                return ;
            }
            if(left < n){
                ans.push_back('(');
                dfs(res,ans,sum+1,left+1,n);
                ans.pop_back();
            }
            if(sum - left < left)
            {
                ans.push_back(')');
                dfs(res,ans,sum+1,left,n);
                ans.pop_back();
            }
        }
        vector<string> generateParenthesis(int n) {
            if(n == 0) return vector<string>(0);
            if(n == 1) return vector<string>(1,"()");
            vector<string> res;
            string ans;
            dfs(res,ans,0,0,n);
            return res;
        }
    };