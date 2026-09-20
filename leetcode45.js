//有点慢

/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
    let n = nums.length;
    if(n == 1) return 0;
    let dp = new Array(n).fill(Number.MAX_SAFE_INTEGER);
    dp[0] = 0;
    for(let i = 0;i < n;++i)
    {
        let temp = dp[i];
        for(let j = 1;j <= nums[i] && i + j < n;++j)
            dp[i + j] = Math.min(dp[i] + 1,dp[i+j]);
    }
    return dp[n-1];
};