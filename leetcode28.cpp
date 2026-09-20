#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int strStr(string haystack, string needle) {
            if(haystack.size() < needle.size()) return -1;

            int m = needle.size();
            int n = haystack.size() - m + 1;
            for(int l = 0;l < n;l++)
            {
                if(haystack[l] == needle[0])
                {
                    int index = l + 1;
                    int nIndex = 1;
                    int flag = 1;
                    while(index - l - 1 < m &&  nIndex< m)
                    {
                        if(haystack[index] != needle[nIndex])
                        {
                            flag = 0;
                            break;
                        }
                        index++,nIndex++;
                    }
                if(flag) return l;
                }
            }
            return -1;
        }
    };