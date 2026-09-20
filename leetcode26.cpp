class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            map<int,int> hash;
            int n = nums.size();
            if(n == 1) return 1;
            for(int i = 0;i < n;i++)
            {
                if(hash[nums[i]] == 0) {hash[nums[i]]++;continue;}
                nums.erase(nums.begin() + i);
                i--;
                n--;
            }
            return nums.size();
        }
    };