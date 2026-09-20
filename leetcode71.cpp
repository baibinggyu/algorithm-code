#include <deque>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
       string res;
       string str;
       deque<string> dq;

       for(char ch : path){
            if(ch == '/'){
                if(str == "..") {if (!dq.empty()) dq.pop_back();}
                else if (str != "." && str != "") dq.push_back(str);
                str.clear();
                continue;
            }
            str += ch;
       }
       
       if(path.back() != '/'){
            if(str == "..") {if (!dq.empty()) dq.pop_back();}
            else if (str != "." && str != "") dq.push_back(str);
       }

       if(dq.empty()) return "/";
       while(!dq.empty()){
            res += "/" + dq.front();
            dq.pop_front();
            
       }

        return res;

    }
};

