#include <vector>
using std::vector;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size() - 1);
        return nums;
    }
    void quickSort(std::vector<int>& arr,int l , int r){
        if(l >= r) return;
        int left = l ,right = r;
        int p = arr[l + ((r - l) >> 1)];
        while(left <= right){
            while(arr[left] < p) left ++;
            while(arr[right] > p) right --;
            if(left <= right){
                std::swap(arr[left],arr[right]);
                left ++;
                right --;
            }
        }
        quickSort(arr,l,right);
        quickSort(arr,left,r);
    }
};