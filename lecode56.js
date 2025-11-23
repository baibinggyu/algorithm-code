/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    res = new Array().fill().map(() => new Array())
    let n = intervals.length;
    intervals.sort((a,b)=>a[0] - b[0])
    let last = intervals[0][0],cur = intervals[0][1]
    for(let i = 1;i < n;++i)
    {
        if(cur < intervals[1][0]){

        }
    }


};