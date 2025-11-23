#include <iostream>
#include <string>
#include <algorithm>
#define int __int128_t
#define double long long double
std::ostream& operator<<(std::ostream& os,int num){
    bool flag = false;
    if(num < 0)flag = true,num = -num;
    if(num == 0 ) os << "0";
    std::string str = "";
    while(num){
        str.push_back('0' + num % 10);
        num /= 10;
    }
    std::reverse(std::begin(str),std::end(str));
    if(flag) str = "-" + str;
    os << str ;
    return os;
}
std::istream& operator>>(std::istream& in,int& num){
    num = 0;
    std::string str;in >> str;
    if(str == "0") return in;
    bool flag = false;
    if(str.front() == '-') flag = true,str.erase(str.begin());
    for(int i = 0;i < static_cast<signed>(str.size());i++){
        num = (str[i] - '0') + num * 10;
    }
    if(flag) num = -num;
    return in;
}


constexpr int left = 0,right = 1e20 + 5;

int pow(int a,int p){
    if(p == 0) return 1;
    int res = 1;
    while(p){
        if(p & 1) res *= a;
        a *= a;
        p  >>= 1;
    }
    return res;
}

bool isLeap(int x){
    
}

int layers(int x){

}

signed main(void){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // int n;std::cin >> n;
    // std::cout << n << std::endl;
    return 0;
}

