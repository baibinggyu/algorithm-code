#include <string>
#include <algorithm>
using std::string;
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        std::sort(std::begin(s1),std::end(s1));
        std::sort(std::begin(s2),std::end(s2));
        return s1 == s2;
    }
};