#include <string>
#include <algorithm>
using std::string;
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
       if (x < y) std::sort(s.begin(), s.end(), std::greater<char>());
       else std::sort(s.begin(), s.end());
       return s;
    }
};©leetcode