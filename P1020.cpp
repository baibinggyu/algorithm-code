#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int main(void){
    std::string line;
    std::getline(std::cin,line);
    std::vector<int> arr;
    std::stringstream iss(line);
    int x = 0;
    while(iss >> x){
        arr.push_back(x);
    }
    std::vector<int> dp(arr.size(),1);
    int max_len =  1;
    for(int i = 0;i < arr.size();i++){
        for(int j = 0;j < i;j++){
            if(arr[j] >= arr[i])
                dp[i] = std::max(dp[i],dp[j] + 1);
        }
        max_len = std::max(dp[i],max_len);
    }
    std::cout << max_len << std::endl;
    std::vector<int> system;
    for(int i =  0;i < arr.size();i++){
        bool isPlace = false;
        for(int j = 0;j < system.size();j++){
            if(system[j] >= arr[i]){
                system[j] = arr[i];
                isPlace = true;
                break;
            }
        }
        if(!isPlace) system.emplace_back(arr[i]);
    }
    std::cout << system.size() << std::endl;
    return 0;
}