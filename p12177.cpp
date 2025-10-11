#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
void pr__int128128(__int128 x){
    if(x == 0){std::cout << '0' << std::endl;return;}
    std::string str;
    while(x){
        str += '0' + (x % 10);
         x/= 10;
    }
    std::reverse(str.begin(),str.end());
    std::cout << str << std::endl;
}
int main(void){
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(std::size_t i = 0;i < arr.size() ;i++) std::cin >> arr[i];
    __int128 bit = 21;
    __int128 bits = 1;
    __int128 res = 0;   
    for(__int128 i = 0;i < bit;i++){
        __int128 count0 = 0;
        __int128 count1 = 0;
        __int128 sum0 = 0;
        __int128 sum1 = 0;
        for(size_t j = 0;j < arr.size();j++){
            if((arr[j] >> i) & 1){
                count1++;
                sum1 += j;
                res += bits * (count0 * j - sum0);
            }else{
                count0++;
                sum0 += j;
                res += bits * (count1 * j - sum1);
            }
        }
        bits <<= 1;
    }
    pr__int128128(res);
    return 0;
}