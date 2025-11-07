    #include <vector>
    #include <algorithm>
    #include <iostream>
    using std::vector;
    class Solution {
    public:
        int movesToMakeZigzag(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return 0;
            std::cout << cmp01(nums) << std::endl;
            std::cout << cmp02(nums) << std::endl;
            return std::min(cmp01(nums),cmp02(nums));
        }
        // a0 > a1 < a2 > a3
        int cmp01(std::vector<int> arr){
            int n = arr.size();
            int count = 0;
            for(int i = 0;i < n;i++){
                if(i & 1){
                    if(i - 1 >= 0 and arr[i - 1] <= arr[i]){
                            int diff = arr[i] - arr[i - 1] + 1;
                            arr[i] -= diff;
                            count += diff;
                        }
                    if(i + 1 < n and arr[i] >= arr[i + 1]){
                        int diff = arr[i ] - arr[i + 1] + 1;
                        arr[i] -= diff;
                        count += diff;
                    }
                }else{  
                    if(i - 1 >=0 and arr[i - 1] >= arr[i]){
                        int diff = arr[i - 1] - arr[i] + 1;
                        arr[i - 1] -= diff;
                        count += diff;
                    }
                    if(i + 1 < n and arr[i] <= arr[i + 1]){
                        int diff = arr[i + 1] - arr[i] + 1;
                        arr[i + 1] -= diff;
                        count += diff;
                    }
                }
            }
            return count;
        }
        // a0 < a1 > a2 < a3
        int cmp02(std::vector<int> arr){
            int n = arr.size();
            int count = 0;
            for(int i = 0;i < n;i++){
                if(i & 1){
                    if(i - 1 >= 0 and arr[i - 1] >= arr[i]){
                        int diff = arr[i - 1] - arr[i] + 1;
                        arr[i - 1] -= diff;
                        count += diff;
                    }  
                    if(i + 1 < n and arr[i] <= arr[i + 1]){
                        int diff = arr[i + 1] - arr[i] + 1;
                        arr[i + 1] -= diff;
                        count += diff;
                    }
                }else{
                    if(i - 1 >=0 and arr[i - 1] <= arr[i]){
                        int diff = arr[i] - arr[i - 1] + 1;
                        arr[i] -= diff;
                        count += diff;
                    }
                    if(i + 1 < n and arr[i] >= arr[i + 1]){
                        int diff = arr[i] - arr[i + 1] + 1;
                        arr[i] -= diff;
                        count += diff;
                    }
                }
            }
            return count;
        }
    };