
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool stringCheck(string s1,string s2){
        if (s1 == s2) return true;
        unordered_map<char,int> hash;
        for(char ch: s1) hash[ch]++;
        for(char ch : s2) hash[ch]--;
        // 至少有一个满足条件
        if (any_of(hash.begin(),hash.end(),[](const pair<char,int>& it)->bool{return it.second != 0;}))
            return false;
        return true;
    }
    bool dfs(int index01,int index02,int length){
        if(vis[index01][index02][length]) return false;
        vis[index01][index02][length] = true;
        if(str01.substr(index01,length) == str02.substr(index02,length)) return true;
        if(!stringCheck(str01.substr(index01,length),str02.substr(index02,length))) return false;
        for(int i = 1;i < length;i++){
            if (dfs(index01,index02,i) && dfs(index01 + i,index02 + i,length - i)) return true;
            if(dfs(index01,index02 + length -i ,i) && dfs(index01 + i,index02,length -i)) return true;
        }
        return false;
    }
    bool isScramble(string s1, string s2) {
        str01 = s1;
        str02 = s2;
        return dfs(0,0,s1.length());
    }
private:
    bool vis[30][30][31] = {0};
    std::string str01,str02;
};