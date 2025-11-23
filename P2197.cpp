#include <iostream>
#include <vector>
int main(void){
    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for(int i = 0 ;i < arr.size();i++) std::cin >> arr[i];
        int ans = 0;
        for(int temp : arr) ans ^= temp;
        if(ans == 0) std::cout << "No" << std::endl;
        else std::cout << "Yes" << std::endl;
    }

    return 0;
}
