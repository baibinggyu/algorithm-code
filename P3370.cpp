#include <iostream>
#include <string>
#include <vector>
#define ll unsigned long long
constexpr int p = 131;
std::vector<int> GetHashArr(std::string& s){
    if(s == "") return std::vector<int>(0);
    std::vector<int> res(s.size());
    res[0] = s[0];
    for(int i = 1;i < (int)s.size();i++){
        res[i] = res[i - 1] * p + s[i];
    }
    return res;
}
ll quickPow(ll a ,ll p){
    ll res = 1;
    while(p){
        if (p & 1) res *= a;
        a *= a;
        p >>= 1;
    }
    return res;
}
ll GetHashValue(std::vector<int>& arr,int l ,int r){
    if(l == 0) return arr[r];
    return arr[r] - arr[l - 1] * quickPow(p,r - l + 1);
}

int main(void){
    int n ;
    std::cin >> n;
    std::vector<std::string> str(n,std::string(""));
    for(int i = 0;i < str.size();i++) std::cin >> str[i];
    std::vector<std::vector<int>> arr(n);
    for(int i = 0;i < arr.size();i++)
        arr[i] = std::move(GetHashArr(str[i]));
    std::vector<bool> vis(n,false);
    int ans = 0;
    for(int i = 0;i < arr.size();i++){
        if(vis[i]) continue;
        ans++;
        for(int j = i + 1;j < arr.size();j++){
            if(arr[i].back() == arr[j].back()) vis[j] = true;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}