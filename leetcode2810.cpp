#include <string>
#include <deque>
#include <algorithm>
using std::string;
class Solution {
public:
    string finalString(string s) {
        int len = s.size();
        std::string res = "";
        res.reserve(s.size());
        for(int i = 0 ;i < len;i++){
            if(s[i] == 'i'){
                std::reverse(std::begin(res),std::end(res));
                continue;
            }
            res += s[i];
        }
    return res;
    }
};