class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        if(nums.empty()) return 0;
        int res = 0;
        int lessCount = 0,midCount = 0,greaterCount = 0;
        for(const auto &num : nums){
            if(num < a){
                res = (res + greaterCount + midCount) % MOD;
                lessCount++;
            }else if(num <= b){
                res = (res + greaterCount) % MOD;
                midCount++;
            }else{
                greaterCount++;
            }
        }
        return res % MOD;
    }
private:
    static constexpr int MOD = 1'000'000'007;
};