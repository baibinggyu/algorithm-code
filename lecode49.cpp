#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> res;
            unordered_map<string,int> hash;
            if(!strs.size()) return res;
            int index = 0;
            for(string s : strs)
            {
                string temp = s;
                sort(temp.begin(),temp.end(),[](char a,char b)->bool{return int(a) - int(b) < 0;});
                if(hash.find(temp) != hash.end()) res[hash[temp]].push_back(s);
                else {
                    hash[temp] = index++;
                    res.push_back(vector<string>(1,s));
                }

            }
            return res;
        }
    };