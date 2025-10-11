#include <iostream>
#include <string>
#include <vector>
std::vector<int> GetNext(std::string s){
    std::vector<int> next(s.size(),0);
    for(int i = 1,j = 0;i < (int)s.size();i++){
        while(j > 0 && s[i] != s[j]) j = next[j - 1];
        if(s[i] == s[j]) next[i] = ++j;
    }
    return next;
}

int main(void){
    int n ;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    auto next = GetNext(s);
    std::cout << n - next.back() << std::endl;

    return 0;
}