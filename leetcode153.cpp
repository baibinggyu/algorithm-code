    #include <vector>
    using std::vector;
    class Solution {
    public:
        int findMin(vector<int>& nums) {
            int l = 0,r = nums.size() - 1;
            int target = nums[0];
            while(l <= r){
                int mid = l + ((r - l) >> 1);
                if(nums[mid] > nums.front()) l = mid + 1;
                else{
                    if(target > nums[mid]) target = nums[mid];
                    if(nums[mid] > nums[l]) r = mid - 1;
                    else l = l + 1;
                }

            }
            return target;
        }
    };