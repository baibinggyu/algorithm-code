/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    dp = new Array(s.length + 1);
    for(let i = 0;i < s.length + 1;++i)
        dp[i] = new Array(p.length + 1).fill(false);
    dp[0][0] = true;
    for(let i = 1;i < p.length + 1;++i)
        if(p[i -1] === '*') dp[0][i] = dp[0][i-1];
        else break;
    for(let i = 1;i < s.length + 1;++i)
        for(let j = 1;j < p.length + 1;++j)
        {
             if(p[j-1] === '?') dp[i][j] = dp[i-1][j-1];
             else if(p[j-1] === '*') dp[i][j] = dp[i][j-1] || dp[i-1][j]; //这里
             else if(s[i-1] === p[j-1]) dp[i][j] = dp[i-1][j-1];
             else  dp[i][j] = false;
        }
    return dp[s.length][p.length];

};