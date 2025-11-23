    #include <iostream>
    #include <vector>
    void quickSort(std::vector<int>& arr,int l,int r){
        if(l >= r) return;
        int left = l,right = r;
        int p = arr[left + ((right - left) >> 1)];
        while(left <= right){
            while(arr[left] < p) left++;
            while(arr[right] > p) right--;
            if(left <= right){
                std::swap(arr[left],arr[right]);
                left++;
                right--;
            } 
        }
        quickSort(arr,l,right);
        quickSort(arr,left,r);
    }

    int main(void){
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for(int i = 0;i < arr.size();i++) std::cin >> arr[i];
        quickSort(arr,0,arr.size() - 1);
        for(auto x : arr) std::cout << x << ' ' ;
        std::cout << std::endl;
        return 0;
    }