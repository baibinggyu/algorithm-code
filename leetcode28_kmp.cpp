#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int strStr(string haystack, string words) {
            int n = haystack.size(),m = words.size();
            vector<int> next(m,-1);
            int i = 0,j = -1;
            while(i < m - 1)
            {
                if(j == -1 || words[i] == words[j]) next[++i] = ++j;
                else j = next[j];
            }
            i = 0,j = 0;
            while(i < n && j < m)
            {
                if(j == -1 || haystack[i] == words[j]) {++i,++j;}
                else j = next[j];
            }
            return j == m ? i - j : -1;
        }
    };