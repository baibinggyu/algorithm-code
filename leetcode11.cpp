#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int i = 0,j = height.size() - 1,res = 0;
            while(i < j)
            {
                int len = j - i;
                res = height[i] < height[j] ? max(res,len*height[i++]) : max(res,len*height[j--]);
            }
            return res;
        }
    };