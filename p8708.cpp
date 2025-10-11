#include <bits/stdc++.h>
constexpr int N = 1e5 + 5;
std::string arr[N];
int cmp(std::string str01,std::string str02){
    if(str01.size() == str02.size()){
        if(str01 < str02) return -1;
        else if (str01 > str02) return 1;
        else return 0;
    }else if (str01.size() < str02.size()) return -1;
    else return 1;
}

int main(void){
    int n;
    std::string k;
    std::cin >> n >> k;
    for(int i = 0;i < n;i++)
        std::cin >> arr[i];
    std::sort(arr,arr+n,[](std::string str01,std::string str02)->bool{
        if(str01.size() == str02.size()){
            if(str01 < str02) return true;
            else return false;
        }else if(str01.size() < str02.size()) return true;
        else return false;
    });
    int count =0;
    int l = 0,r = n - 1;
    while(l <= r){
        int temp = cmp(arr[l] + arr[r],k);
        if(temp == -1){
            count += r - l;
            l++;
        }else if (temp == 0){
            count += r - l;
            l++,r--;
        }else{
            r--;
        }
    }
    l = 0,r = n - 1;
    while(l <= r){
        int temp = cmp(arr[r] + arr[l],k);
        if(temp == -1){
            count += r - l;
            l++;
        }else if (temp == 0){
            count += r - l;
            r--,l++;
        }else{
            r--;
        }
    }
    std::cout << count << std::endl;



    return 0;
}