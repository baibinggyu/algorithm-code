#include <iostream>
#include <vector>
void Print(std::vector<int>& arr){
    for(int i = 0;i < (int)arr.size();i++) std::cout << arr[i] << ' ' ;
    std::cout << std::endl;
}
void quickSort(std::vector<int>& arr,int left,int right){
    if(left >= right) return;
    int l = left,r = right;
    int p = arr[(l + r) >> 1];
    while(l < r){
        while (l < r && arr[l] < p) l++;
        while (l < r && arr[r] > p) r--;
        if(l <= r){
            std::swap(arr[l],arr[r]);
            l++;
            r--;
        }
        Print(arr);
    }
    quickSort(arr,left,l - 1);
    quickSort(arr,l + 1,right);
}
#define LIST {9,8,7,6,5,4,3,2,1}
int main(void){
    std::vector<int> arr = LIST;
    Print(arr);
    quickSort(arr,0,arr.size() - 1);
    for(auto p = arr.begin();p != arr.end();p++) std::cout << *p << ' ' ;
    std::cout << std::endl;
    return 0;
}