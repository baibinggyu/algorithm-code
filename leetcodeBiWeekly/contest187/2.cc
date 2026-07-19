#define int long long
class Solution {
public:
    // 3 7 7  输出14 预期14
    // 3 4 4  输出6 预期7 
    // 169838 746752 36233 超出范围
    long long maximumValue(int n, int s, int m) {
        if (n == 1) return s;        
        if (n % 2 == 0){
            return s + (n - 1) / 2 * (m - 1) + m;
        }else{
           // 为odd 
            return s + (n - 1) / 2 * (m - 1) + 1;
        }

    }
};
#undef int