#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution {
    public:
        int lengthOfLastWord(string s) {
            int n = s.size();
            int index = n - 1;
            int count = 0;
            while(~index && !isalpha(s[index])) index--;
            while(~index && isalpha(s[index])) {count++;index--;}
            return count;
        }
    };