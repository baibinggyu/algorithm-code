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
    for(int i = 0;i < n;i++) std::cin >> arr[i];
    std::sort(arr,arr+n,[](std::string str01,std::string str02){
        if(str01.size() == str02.size()){
            if(str01 < str02) return true;
            else return false;
        }else if(str01.size() < str02.size()) return true;
        else return false;
    });
    int count = 0;
    for(int i = 0;i < n - 1;i++){
        int l = i + 1,r = n - 1;
        while(l <= r){
            int mid = l + ((r - l) >> 1);
            int temp = cmp(arr[i] + arr[mid],k);
            if(temp == -1) l = mid + 1;
            else if (temp == 0){
                l = mid + 1;
                break;
            }else{
                r = mid - 1;
            }
        }
        if(r == i) continue;
        count += l - 1 - i;
    }

    for(int i = 0;i < n - 1;i++){
        int l = i + 1,r = n - 1;
        while(l <= r){
            int mid = l + ((r - l) >> 1);
            int temp = cmp(arr[mid] + arr[i],k);
            if(temp == - 1) l = mid + 1;
            else if (temp == 0){
                l = mid + 1;
                break;
            }else{
                r = mid - 1;
            }
        }
        if(r == i) continue;
        count += l - 1 - i;
    }

    std::cout << count << std::endl;


    return 0;
}