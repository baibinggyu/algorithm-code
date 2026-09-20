/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    const n = nums.length;
    if(n == 1) return nums[0];
    const dp = new Array(n).fill(Number.MIN_SAFE_INTEGER);
    dp[0] = nums[0];
    for(let i = 1;i < n;++i)
        dp[i] = Math.max(dp[i-1] + nums[i],nums[i]);
    let res = Number.MIN_SAFE_INTEGER;
    for(let i of dp)
        res = Math.max(i,res);
    return res;
};