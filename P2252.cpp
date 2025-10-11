#include <iostream>
#include <vector>
#include <algorithm>
void print(std::vector<std::vector<int>> &arr){
    for(int i =  0;i < arr.size();i++){
        for(int j = 0;j < arr[0].size();j++){
            printf("arr[%d][%d] = %d ",i,j,arr[i][j]);
        }
        putchar('\n');
    }
}
signed main(void){
    int a , b;
    std::cin >> a >> b;
    if (a > b){
        std::swap(a,b);
    }
    std::vector<std::vector<int>> arr(a + 1,std::vector<int>(b + 1, 0));
    if (a == 0 and b == 0){
        std::cout << -1 << std::endl;
        return  0;
    }
    if((a == 0 || b == 0) || (a == b)){
        std::cout << 1 << std::endl;
        return 0;
    }
    for(int i = 0;i < arr[0].size();i++) arr[0][i] = 1;
    for(int i = 0;i < arr.size();i++) arr[i][0] = 1;
    arr[0][0] = 0;
    for (int i = 1 ;i < arr.size() ;i++){
        for(int j = 1;j < arr[0].size() ;j++){
           if (i == j) arr[i][j] = 1;
            else{
                bool flag = false;
                for(int k = 1;k < i ;k++) if (arr[k][j] == 0) {arr[i][j] = 1; flag = true;}
                if (flag) continue;
                for(int k = 1;k < j;k++) if (arr[i][k] == 0) {arr[i][j] = 1;flag = true;}
                if(flag) continue;
                for(int k = 1;k <= std::min(i,j);k++) if(arr[i - k][j - k] == 0) arr[i][j] = 1;
            }
        }
    }
    // print(arr);
    std::cout << arr.back().back() << std::endl;
    return 0;
}