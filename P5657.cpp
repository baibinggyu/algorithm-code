#include <iostream>
#include <vector>
#include <string>
#include <bitset>

int main(void){
    long long n , k;
    std::cin >> n >> k;
    std::vector<long long> num(2,0);
    num[1] = 1;
    long long p = 1;
    for(int i = 1;i < n;i++){
        p *= 2;
        for(int i = num.size() - 1;~i;i--) num.emplace_back(p + num[i]);
    }
    std::bitset<64> b(num[k]);
    std::string value = b.to_string();
    std::cout << value.substr(value.size() - n) << std::endl;
    
    return 0;
}


/*
n == 0
    0
n == 1
    0 1     2^(n ) - 1 
n == 2
    00 01 10 11         2 ^ n - 1 + index = curIndex
                        
n == 3
    000 001 010 011 111 110 101 100

2 ^ n ->数据的量
index = k
if index > 


*/