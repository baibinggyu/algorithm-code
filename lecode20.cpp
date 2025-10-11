#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool isValid(string s) {
            stack<char> res;
            for(int i = 0 ;i < s.size();i++)
                if(s[i] == '(') res.push('(');
                else if (s[i] == '[') res.push('[');
                else if (s[i] == '{') res.push('{');
                else if (!res.empty() && res.top() == '(' && s[i] == ')') res.pop();
                else if (!res.empty() && res.top() == '[' && s[i] == ']') res.pop();
                else if (!res.empty() && res.top() == '{' && s[i] == '}') res.pop();
                else return false;
            return res.empty();
        }
    };