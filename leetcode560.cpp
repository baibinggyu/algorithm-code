    #include <vector>
    #include <iostream>
    #include <unordered_map>
    using std::vector;
    class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();    
        std::vector<int> pre(n);
        std::unordered_map<int,int> hash;
        int res= 0;
        hash[0] = 1;
        pre.front() = nums.front();
        for(int i = 1;i < n;i++) pre[i] = pre[i - 1] + nums[i];
        for(int i = 0;i < n;i++){
            if(hash.count(pre[i] - k)){
                res += hash[pre[i] - k];
            }
            hash[pre[i]]++;
        }
        return res;
    }
};