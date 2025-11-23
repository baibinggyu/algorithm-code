#include <iostream>
#include <vector>
#include <algorithm>
int main(void){
    int n;
    std::cin >> n;
    std::vector<int> height(n);
    for(int i = 0;i < height.size();i++) std::cin >> height[i];
    std::vector<int> lstr(n),rstr(n);
    lstr[0] = 1,rstr[rstr.size() - 1] = 1;
    std::vector<int> ldp,rdp;
    ldp.push_back(height.front()),rdp.push_back(height.back());
    for(int i = 1 ;i < height.size();i++){
        if(ldp.back() < height[i]){
            ldp.push_back(height[i]);
        }else{
            int l = 0,r = ldp.size() - 1;
            while(l < r){
                int mid = l + ((r - l) >> 1);
                if (ldp[mid] < height[i]) l = mid + 1;
                else r = mid;
            }
            ldp[l] = height[i];
        }
        lstr[i] = ldp.size();
    }
    for(int i = height.size() - 2;~i;i--){
        if(rdp.back() < height[i]){
            rdp.push_back(height[i]);
        }else{
            int l = 0,r = rdp.size() - 1;
            while(l < r){
                int mid = l + ((r - l) >> 1);
                if (rdp[mid] < height[i]) l = mid + 1;
                else r = mid;
            }
            rdp[l] = height[i];
        }
        rstr[i] = rdp.size();
    }
    int res = 0;
    for(int i = 0;i < lstr.size();i++){
        res = std::max(res,lstr[i] + rstr[i] - 1);
    }
    std::cout << n - res << std::endl;
    return 0;
}