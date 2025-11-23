#include <iostream>
#include <vector>
#include <string>
#include <map>
#define int long long
signed main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string str;
    std::getline(std::cin,str);
    std::string tempStr;
    std::map<std::string,int> hash;
    for(int i = 0;i < static_cast<int>(str.size());i++){
        if(::isalpha(str[i])){
            if(std::isupper(str[i])) str[i] = std::tolower(str[i]);
            tempStr.push_back(str[i]);
        }else {
            if(tempStr.size() == 0) continue;
            hash[tempStr]++;
            tempStr.clear();
        }
    }
    // for(auto& x : hash){
    //     std::cout << x.first << std::endl;
    //     std::cout << "----------------" << std::endl;
    // }
    if(tempStr.size() != 0 ) hash[tempStr]++;
    int memCount;std::cin >> memCount;
    int count = hash.size();
    std::map<std::string,int> dic;
    for(int i = 0 ;i < memCount;i++){
        std::string str;
        std::cin >> str;
        if(hash.count(str) and not dic.count(str)){
            dic[str] ++;
            count--;
        }
    }
    std::cout << count << std::endl;
    return 0;
}