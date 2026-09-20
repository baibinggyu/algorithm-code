#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int cmpMax(int n,int m){return n > m? n : m;}
        int cmpMin(int n,int m){return n < m? n : m;}
        int maxArea(vector<int>& height) {
            int volume = 0;
            int n = height.size();
            int len = 0;
            for(int i = 0;i < n;i++)
            {
                for(int j = i + 1;j < n;j++)
                {
                    int h = cmpMin(height[i],height[j]);
                    int len = j - i;
                    volume = cmpMax(volume,h * len );
                }
            }

        return volume;
        }
    };