#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;    
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        std::sort(pairs.begin(),pairs.end(),[](std::vector<int>& a,std::vector<int>& b)->bool{return a.front() < b.front();});
        std::vector<std::vector<int>> dp;
        dp.push_back(pairs.front());
        for(int i = 1;i < (int)pairs.size();i++){
            auto it = std::lower_bound(dp.begin(),dp.end(),pairs[i],[](const std::vector<int>& a,const std::vector<int>& b)->bool{return a.back() < b.front();});
            if(it == dp.end()){
                dp.push_back(pairs[i]); 
            }else{
                if((*it).back() > pairs[i].back())
                    *it = pairs[i];
            } 
        }
        return dp.size();
    }
};  