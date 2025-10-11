#include <iostream>
#include <string>
#include <vector>
std::vector<int> getNext(std::string s){
    if(s == "") return std::vector<int>();
    std::vector<int> next(s.size(),0);
    int j = 0;
    for(int i = 1;i < (int)next.size();i++){
        while(j > 0 && s[i] != s[j]){
            j = next[j - 1];
        }
        if(s[i] == s[j]) j++;
        next[i] = j;
    }
    return next;
}

int main(void){
    std::string s1,s2;
    std::cin >> s1 >> s2;
    std::vector<int> next = getNext(s2);
    std::vector<int> ans;
    for(int i = 0,j = 0;i < (int)s1.size();i++){
        while(j > 0 && s1[i] != s2[j]) j = next[j - 1];
        if(s1[i] == s2[j]) j++;
        if(j == (int)s2.size()) ans.push_back(i -j + 2);
    }
    for(auto x : ans) std::cout << x << std::endl;
    for(auto x : next) std::cout << x << ' ';
    std::cout << std::endl;
    return 0;
}
