#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,-1),right(n,n);
        {stack<int> stk;
        for(int i = 0;i < heights.size();i++){
            if(stk.size() && heights[stk.top()] > heights[i]){
                while(stk.size() && heights[stk.top()] > heights[i]){
                    right[stk.top()] = i;
                    stk.pop();
                }
            }
            stk.push(i);
        }
        }

        {
        stack<int> stk;
        for(int i = n - 1;~i;i--){
             if(stk.size() && heights[stk.top()] > heights[i]){
                while(stk.size() && heights[stk.top()] > heights[i]){
                    left[stk.top()] = i;
                    stk.pop();
                }
            }
                stk.push(i);
        }
        }
        int res = 0;
        for(int i = 0;i < heights.size();i++){
            res = std::max(res,heights[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
};  