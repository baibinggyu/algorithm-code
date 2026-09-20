    #include <vector>
    using std::vector;
    class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            std::vector<int> res;
            for(int i = 0;i < numbers.size();i++){
                int val = target - numbers[i];
                int flag = bs(numbers,val);
                if(flag != -1 and i != flag) {
                    int num01 = i + 1,num02 = flag + 1;
                    if(num01 > num02) std::swap(num01,num02);
                    res.push_back(num01),res.push_back(num02);
                    break;
                }
            }
            return res;
        }
        int bs(std::vector<int>& nums,int val){
            int l = 0,r = nums.size() - 1;
            while(l <= r){ 
                int mid = l + ((r - l) >> 1);
                if(nums[mid] == val) return mid;
                if(nums[mid] > val){
                    r = mid - 1;
                }else{
                    l = mid + 1;    
                }
            }   
            return -1;
        }
    };
