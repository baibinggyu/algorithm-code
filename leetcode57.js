/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
    const res = []
    const n = intervals.length
    let last = newInterval[0]
    let cur = newInterval[1]
    flag = true
    for(let i = 0;i < n;++i)
    {   
        if(flag){
           if(last <= intervals[i][0] && cur >=intervals[i][0]){
                cur = Math.max(cur,intervals[i][1])
                continue
           }else if(last >= intervals[i][0] && last <= intervals[i][1]){
                cur = Math.max(cur,intervals[i][1])
                last = intervals[i][0]
                continue
           }
            if(cur < intervals[i][0]) {
                res.push([last,cur])
                flag = false
                --i
                continue
            }
        }
        res.push(intervals[i])
    }
    if(flag) res.push([last,cur])
    return res;
};