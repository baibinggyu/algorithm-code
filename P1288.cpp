#include <iostream>
#include <vector>
#include <unordered_map>
int main(void){
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i = 0;i < arr.size();i++) std::cin >> arr[i];
    for(int i = 0;i < arr.size();i++){
        if(arr[i] == 0) {
            if ((i + 1) % 2 == 0) return puts("YES"),0;
            break;
        }
    }
    for(int i = arr.size() - 1;~i;i--){
        if(arr[i] == 0) {
            if ((arr.size() - i) % 2 == 0) return puts("YES"),0;
            break;
        }
    }
    puts("NO");
    return 0;
}