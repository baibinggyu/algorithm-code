/**
 * @param {number[]} nums
 * @return {number[][]}
 */

var permuteUnique = function(nums) {
    const n = nums.length;
    if(n === 1) return [nums];
    nums.sort((a,b)=> a - b);
    const res = [];
    const temp = [];
    const pass = new Array(n).fill(false); // 判断是否访问过
    function dfs(current){
        if(current == n){
            res.push([...temp]);
            return;
        }
        for(let i = 0;i < n;++i){
            if(pass[i] || i && nums[i] == nums[i-1] && !pass[i-1]) continue;
            temp[current] = nums[i];
            pass[i] = true;
            dfs(current + 1);
            pass[i] = false;
        }
    }
    dfs(0);
    return res;

};