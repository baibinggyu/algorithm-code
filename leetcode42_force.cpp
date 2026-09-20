#include <climits>
#include <vector>
using namespace std;
class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size();
            if(n == 1 || n == 2) return 0;
            vector<int> maxL(n,0);
            vector<int> maxR(n,0);
            int l = 1,r = n - 2;
            int maxl = 0,maxr = 0;
            while(l < n)
            {
                if(height[l - 1] > maxl)
                    maxl = height[l-1];
                maxL[l] = maxl;
                l++;
            }
            while(r != -1)
            {
                if(height[r + 1] > maxr)
                    maxr = height[r+1];
                maxR[r] = maxr;
                r--;
            }
            int res = 0;
            for(int i = 0;i < n;i++)
            {
                int temp = maxL[i] > maxR[i] ? maxR[i] : maxL[i];
                int n = temp - height[i];
                if(n > 0) res += n;
            }
            return res;
        }
    };