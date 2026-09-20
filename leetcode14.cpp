#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int line = strs.size();
            int index = 0;
            char test = '1';
            while(test)
            {
                test = strs[0][index];
                for(int i = 0;i < line;i++)
                {
                    if(index > strs[i].size() || test != strs[i][index])
                        goto res;
                }
                index++;
            }
            res:
                return strs[0].substr(0,index);
        }
    };