#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define MOD 7
// void print(std::unordered_map<int,std::vector<int>>& hashtable){
//     for (std::unordered_map<int,std::vector<int>>::iterator it = hashtable.begin();it != hashtable.end();it++){
//         for (int i = 0;i < (it->second).size();i++)
//             std::cout << (it->second)[i] << ' '  ;
//         std::cout << std::endl;
//     }
// }
int main(void){
    int n;
    std::cin >> n;
    std::vector<int> id(n);
    for(int i = 0;i < id.size();i++) std::cin >> id[i];
    std::vector<int> s(id.size(),0);
    s[0] = id[0];
    for (int i = 1;i < s.size();i++) s[i] = s[i - 1] + id[i];                           
    std::unordered_map<int,std::vector<int>> hashtable;
    int cur = 0;
    int res = 0;
    for (int temp : s) hashtable[temp % MOD].push_back(cur++);
    // print(hashtable);
    for(auto& p : hashtable){
        if(p.second.empty()) continue;
        res = std::max(res,p.second.back() - p.second.front());
    }
    for(int i =  0;i < s.size();i++)
        if(s[i] % MOD == 0)
            res = std::max(res,i + 1);
    std::cout << res << std::endl;
    return 0;
}