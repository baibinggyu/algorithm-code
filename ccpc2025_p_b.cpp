#include <iostream>
#include <string>
#include <algorithm>
int main(void){
    std::string str;std::cin >> str;
    std::reverse(std::begin(str),std::end(str));
    std::cout << str << std::endl;
}