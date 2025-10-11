#include <iostream>
#include <vector>
int main(void){
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i =  0;i < arr.size();i++) std::cin >> arr[i];
    int res = 0;
    for(int i =  0;i < arr.size();i++) res ^= arr[i];
    std::cout <<res << std::endl;
}
/*
    3
    1 2 5
    1 10 101    
*/