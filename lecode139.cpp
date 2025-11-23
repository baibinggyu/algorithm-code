#include <string>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        len = s.size();
        for(string str : wordDict)
            word.insert(str);
            return dfs(0,s);
    }
    bool dfs(int start,string& s){
        if (start == len) return true;
        if(vis.count(start)){
            return vis[start];
        }
        for (int end = start + 1;end < len + 1;end++){
            if(word.count(s.substr(start,end - start)) && dfs(end,s)){
                vis[start] = true;
                return true;
            }
        }
        vis[start] = false;
        return false;
    }
private:
    unordered_map<int,bool> vis;
    set<string> word;
    int len;
};
// int main(void){
//     Solution ans;
//     vector<string> str({"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"});
//     printf("%d\n",ans.wordBreak(string("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"),
//     str));
//     return 0;
// }