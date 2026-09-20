            #include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int l = 0,r = (x >> 1) + 1;
        while(l < r){
            int mid = l + ((r -l) >> 1) + 1;
            if(1ll * mid * mid == x) return mid;
            else if(1ll * mid * mid * 1l < x) l = mid + 1;
            else r = mid - 1;
        }
        return (l + r) >> 1; 

    }
};