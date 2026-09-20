//双指针
#include <vector>
using namespace std;
class Solution {
    public:
        int trap(vector<int>& height) {
            int n = height.size();
            if(n == 1 || n == 2) return 0;
            int l = 1,r = n - 1;
            int leftCeil = height.front(),rightCeil = height.back();
            int res = 0;
            while(l <= r)
            {
                if(leftCeil < rightCeil)
                {
                    if(height[l] < leftCeil)
                        res += leftCeil - height[l];
                    leftCeil = max(height[l],leftCeil);
                    l++;
                }
                else{
                    if(height[r] < rightCeil)
                        res += rightCeil - height[r];
                    rightCeil = max(rightCeil,height[r]);
                    r--;
                }
            }
            return res;
        }
    };