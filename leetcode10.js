/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var match = function(i,j,s,p)
{
    if(i == 0) return false;
    if(p[j - 1] == '.') return true;
    else return s[i - 1] == p[j-1];
}
var isMatch = function(s, p) {
    var dp = new Array(s.length + 1).fill().map(() => new Array(p.length + 1).fill(false));
    dp[0][0] = true;
    
    for(let i = 0;i < s.length + 1;++i)
    {
        for(let j = 1;j < p.length + 1;++j)
        {
            if(i > 0 && p[j - 1] != '*')
                dp[i][j] = match(i,j,s,p) && dp[i-1][j-1];
            else if( p[j - 1] == '*') {
                if(i > 0 && match(i,j-1,s,p)) dp[i][j] = dp[i-1][j] || dp[i][j-2];
                else dp[i][j] = dp[i][j-2]; 
            }
        }
    }
    return dp[s.length][p.length];
}